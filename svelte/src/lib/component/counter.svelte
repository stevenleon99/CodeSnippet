<script lang="ts">
    let count = $state(0);
    let frequency = $state(1000);
    let pause = $state(false);
    $effect(() => {
        let interval: ReturnType<typeof setInterval>;
        if (!pause) {
            interval = setInterval(() => {
            // console.log({ count, frequency }); // will not track the count as dependency
            count += 1;
        }, frequency);
        }
        return () => {
            clearInterval(interval);
        };
    });
    
</script>

<h1>Counter: {count}</h1>
<button onclick={() => {
    frequency *= 2 ;
}}>Slower</button>

<button onclick={() => {
    frequency /= 2 ;
}}>Faster</button>

<button onclick={() => {
    pause = !pause ;
}}>{pause ? 'Resume' : 'Pause'}</button>

<button onclick={() => {
    count = 0 ;
    const temp = frequency;
    frequency = -1;
    frequency = temp;
}}>Reset</button>