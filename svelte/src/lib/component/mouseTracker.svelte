<script lang="ts">
	import { onMount } from "svelte";

    onMount(() => {
        console.log("MouseTracker component mounted");
        window.addEventListener('mousemove', (event) => {
            console.log(`Mouse moved to: (${event.clientX}, ${event.clientY})`);
        });
    });

</script>

<div>
    <h2>Mouse Tracker Component Demo:</h2>
</div>

