<script lang="ts">
    let randNum = $state((Math.random() * 10) + 1);
    // derive value is synchronouse but the effect function will be pushed to microstack
    // so that don't use derive value to synchronously update another state value
    let randNumDerived = $derived.by(() => randNum * 2);

</script>

<h2>Random Number: {randNum}</h2>
<h2>Random Number Derived (x2): {randNumDerived}</h2>
<button onclick={() => {
    randNum = (Math.random() * 10) + 1;
    console.log('New Random Number Generated:', randNum);
}}>
    Generate New Random Number</button>

<style>
    h2 {
        color: darkorange;
    }
</style>