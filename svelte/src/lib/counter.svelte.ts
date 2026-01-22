function createCounter() {
    let count = $state(0);
    
    return {
        get value() {
            return count;
        },
        increment: () => {
            count+=1;
        },
        reset: () => {
            count = 0;
        }
    }
}

export default createCounter;


class Counter {
    // svelte will create a reactive store for this field (get and set)
    value = $state(0); 

    constructor() {}
    
    increment() {
        this.value += 1;
    };

    reset() {
        this.value = 0;
    };
}

export { Counter };