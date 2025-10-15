def fibonacci(n):
    fib = [0, 1] + [0]*(n-1)
    for i in range(2, n+1):
        fib[i] = fib[i-1] + fib[i-2]
    return fib[n]

if __name__ == "__main__":
    n = int(input("Enter n: "))
    print(f"Fibonacci number {n}:", fibonacci(n))
