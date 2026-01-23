<script lang="ts">
	import { setContext, type Snippet } from "svelte";

    let {children}: {children: Snippet} = $props();

    setContext<number>('count', 0);
</script>

{@render children()}