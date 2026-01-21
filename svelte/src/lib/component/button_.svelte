<script lang="ts">
	import { stopPropagation } from "svelte/legacy";

    interface ButtonProps {
        text: string;
        level?: string;
        size?: 'small' | 'medium' | 'large';
        shadow?: boolean;
        onLeftHover?: () => void;
    }
    let {text, level, size = "medium", shadow = false, onLeftHover}: ButtonProps = $props();
    let buttonElement: HTMLButtonElement;

    export function focus() {
        buttonElement.focus();
    }
</script>

{#snippet sum(a:number, b:number)}
    {#snippet bold(x:any)}
        <b>{x}</b>
    {/snippet}
    <span>{a} + {b} = {@render bold(a + b)}</span>
{/snippet}

<!-- using class directive :: class: -->
<!-- using style directive (overwrite class directive) :: style: -->
<button bind:this={buttonElement}
        class:shadow={shadow} 
        class:sm={size === "small"}   
        class:md={size === "medium"} 
        class:lg={size === "large"}
        style:background-color={level === "primary" ? "#007BFF" : "#6c757d"}
        onmouseenter={() => onLeftHover && onLeftHover()}
        onclick={(e) => {
            console.log(`click from button`);
            e.stopPropagation();
        }}
        onfocus={() => console.log("Button focused")}
        >
        {text ? text : "undefined"}
</button>

{@render sum(3, 5)}
<p>The button level is: {level ? level : "undefined"}</p>
<svelte:element this={'p'}>
    <b>{`Display Level by Svelte Element: ${level ? level : "undefined"}`}</b>
</svelte:element>   

<style lang="scss">
    button {
        border: none;
        border-radius: 4px;
        background-color: #007BFF;
        color: white;
        width: auto;
        cursor: pointer;

        &.sm {
            height: 1cm;
            font-size: 0.8em;
            padding: 0.3em 0.6em;
        }
        &.md {
            height: 2cm;
            font-size: 1em;
            padding: 0.5em 1em;
        }
        &.lg {
            height: 3cm;
            font-size: 1.2em;
            padding: 0.7em 1.4em;
        }
        &.shadow {
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
        }

    }

    button:hover {
        background-color: #0056b3;
    }
</style>