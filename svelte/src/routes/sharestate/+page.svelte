<script lang="ts">
	import ClickToCount from '$lib/component/ClickToCount.svelte';
	import DoubleClickToCount from '$lib/component/DoubleClickToCount.svelte';
	import Counters from '$lib/component/Counters.svelte';
</script>

<div>
	<Counters>
		<ClickToCount />
		<ClickToCount />
	</Counters>

	<Counters>
		<ClickToCount />
		<ClickToCount />
	</Counters>
</div>



<style>
	:global {
		body {
			background-color: #222;
			color: #fff;
		}
	}
</style>