const rates: Record<string, Record<string, number>> = {
    "USD": {
        "EUR": 0.85,
        "JPY": 110.0,
        "USD": 1.0
    },
    "EUR": {
        "USD": 1.18,
        "JPY": 129.53,
        "EUR": 1.0
    },
    "JPY": {
        "USD": 0.0091,
        "EUR": 0.0077,
        "JPY": 1.0
    }
};

export { rates };

