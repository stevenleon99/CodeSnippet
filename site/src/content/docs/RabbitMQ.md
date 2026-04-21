---
title: RabbitMQ
description: RabbitMQ messaging with TLS/NGINX proxy configuration.
---

RabbitMQ messaging with TLS/NGINX proxy configuration.

## Architecture

The setup uses NGINX as a TLS-terminating reverse proxy in front of RabbitMQ:

1. Client initiates TLS connection to NGINX (public port 5671)
2. NGINX performs access checks (IP allowlist, connection limits per IP)
3. Allowed connections are proxied to RabbitMQ on localhost:5672
4. Communication is encrypted outside, plaintext AMQP inside

## Key Configuration

- TLS termination at NGINX with Let's Encrypt certificates
- IP-based access control (`geo` directive)
- Connection limiting (max 20 connections per IP)
- Idle timeout handling via `proxy_timeout`
