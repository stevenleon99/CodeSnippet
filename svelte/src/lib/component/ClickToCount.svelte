<script lang="ts">
import Button from "./Button.svelte";
import createCounter from "$lib/counter.svelte";

const counter = createCounter();

</script>

<div class="wrapper">
	<!-- instead of counter.value, use this method to get the reactive value -->
	<h2>{counter.getValue()}</h2> 
	<Button --buttonBgColor="#000" onclick={counter.increment}>Increment</Button>
	<Button --buttonBgColor="#fff" --buttonTextColor="#000" onclick={counter.reset}>Reset</Button>
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