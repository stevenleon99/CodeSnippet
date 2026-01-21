<script lang="ts">
	import ClickToCount from '$lib/component/ClickToCount.svelte';
	import DoubleClickToCount from '$lib/component/DoubleClickToCount.svelte';
</script>

<ClickToCount />
<DoubleClickToCount />

<style>
	:global {
		body {
			background-color: #222;
			color: #fff;
		}
	}
</style>