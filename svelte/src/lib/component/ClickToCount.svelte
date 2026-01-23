<script lang="ts">
	import Button from "./Button.svelte";
	import createCounter from "$lib/counter.svelte";
	import Counter from "$lib/counter.svelte";
	import { getShareCount, incrementShareCount,resetShareCount } from "$lib/shareCount.svelte";
		import { getContext } from "svelte";

	const counter = createCounter();
	const counter2 = new Counter();

	let count = getContext<number>('count');
	console.log('Initial shared count:', count);

</script>

<div class="wrapper">
	<!-- instead of counter.value, use this method to get the reactive value -->
	<h2>{getShareCount()}</h2> 
	<Button --buttonBgColor="#000" onclick={incrementShareCount}>Increment</Button>
	<Button --buttonBgColor="#fff" --buttonTextColor="#000" onclick={resetShareCount}>Reset</Button>
</div>

<style>
	.wrapper {
		text-align: center;
		background-color: #111;
		padding: 20px;
		border-radius: 10px;
		margin-bottom: 10px;
		h2 {
			font-size: 60px;
			margin: 0 0 20px;
			line-height: 1;
		}
	}
</style>