import psutil, sys, time
p = psutil.Process(int(sys.argv[1]))
print(p)
print(p.name())
for _ in range(100):
    m = p.memory_info().rss / (1024*1024)
    cpu = p.cpu_percent(interval=1.0)
    print(f"RSS: {m:.1f} MB | CPU: {cpu:.1f}% | Threads: {p.num_threads()}")
    time.sleep(0.1)