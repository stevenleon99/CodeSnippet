<script lang="ts">
	import Button from './Button.svelte';
	import { getShareCount, incrementShareCount,resetShareCount } from "$lib/shareCount.svelte";

	let count = $state(0);
	function increment() {
		count += 1;
	}
	function reset() {
		count = 0;
	}
</script>

<div class="wrapper">
	<h2>{getShareCount()}</h2>
	<Button --buttonBgColor="#000" ondblclick={incrementShareCount}>Increment</Button>
	<Button --buttonBgColor="#fff" --buttonTextColor="#000" onclick={resetShareCount}>Reset</Button>
</div>

<style>
	.wrapper {
		text-align: center;
		background-color: #ff3e00;
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