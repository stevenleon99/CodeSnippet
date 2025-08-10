sequenceDiagram
    participant C as Client (AMQP over TLS)
    participant N as NGINX (stream proxy :5671 ssl)
    participant R as RabbitMQ (AMQP :5672)

    Note over C,N: Client initiates TLS connection to NGINX (public)
    C->>N: TCP SYN (to 5671)
    N-->>C: TCP SYN-ACK
    C->>N: TLS ClientHello
    N-->>C: TLS ServerHello + Cert (Let's Encrypt)

    rect rgb(245,245,245)
    Note over N: Access checks
    N->>N: Determine client IP → $binary_remote_addr
    N->>N: geo $amqp_allowed (allowlist?)
    alt Not allowed
        N-->>C: return 444 (drop); close
        deactivate N
        deactivate C
    else Allowed
        N->>N: limit_conn amqp_conn_zone (<= 20/IP)
        alt Over the limit
            N-->>C: connection rejected/closed
            deactivate N
            deactivate C
        else Under the limit
            Note over N,R: Internal connect to RabbitMQ
            N->>R: TCP connect (127.0.0.1:5672)
            R-->>N: TCP established
        end
    end
    end

    Note over C,N,R: Encrypted outside, plaintext AMQP inside
    C->>N: TLS app data (AMQP frames)
    N->>R: AMQP frames (proxied)
    R-->>N: AMQP frames / acks
    N-->>C: TLS app data (proxied back)

    Note over C,N,R: Idle > proxy_timeout? NGINX closes both sides
    C-xN: FIN/Close
    N-xR: FIN/Close
