<script lang="ts">
    import { onDestroy, onMount, tick, untrack } from 'svelte';
    let randNum = $state(Math.floor(Math.random() * 10) + 1);
    // derive value is synchronouse but the effect function will be pushed to microstack
    // so that don't use derive value to synchronously update another state value
    let randNumDerived = $derived.by(() => randNum * 2);
    let history: number[] = $state([untrack(() => randNum)]); // later change of randNum will not affect history
    let historyPTage: HTMLParagraphElement; // reference to paragraph element
    
    // onMount runs when component is mounted, only once
    onMount(() => {
        console.log('Component mounted. Initial Random Number:', randNum);
        return () => {
            console.log('Component unmounted.');
        };
    });

    // effect.pre will run before DOM update because historyPTage is logged as undefined
    $effect.pre(() => {
        history.length;
        if (historyPTage) {
            console.log('historyPTage exists in $effect.pre');
        } else {
            console.log('historyPTage is undefined in $effect.pre');
        }
        // tick will wait for DOM update
        tick().then(() => {
            console.log('$effect.pre after tick', historyPTage.innerHTML);
        });
        return ()  => {
            console.log('$effect.pre cleanup');
        };
    });

    // effect will run after DOM update because historyPTage is not logged as undefined
    $effect(() => {
        history.length;
        console.log('$effect', historyPTage.innerHTML);
        return ()  => {
            console.log('$effect cleanup');
        };
    });

    // onDestroy runs when component is unmounted, only once
    onDestroy(() => {
        console.log('onDestroy called.');
        return () => {
            console.log('onDestroy cleanup called.');
        };
    });

</script>

<h2>Random Number: {randNum}</h2>
<h2>Random Number Derived (x2): {randNumDerived}</h2>
<p bind:this={historyPTage}>History: {history}</p>
<button onclick={() => {
    randNum = Math.floor(Math.random() * 10) + 1;
    console.log('New Random Number Generated:', randNum);
    history.push(randNum);
}}>
    Generate New Random Number</button>

<style>
    h2 {
        color: darkorange;
    }
</style>