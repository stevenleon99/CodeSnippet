<script lang="ts">
    import Button from '$lib/component/button_.svelte';
    let buttonElement: Button;

    $effect(() => {
        if (buttonElement) {
            buttonElement.focus();
        }
    });
</script>

<div>
    <p>Button Component Demo:</p>
    <div>
        <Button text="Click Me!" level="primary" size="small" shadow={false} />
    </div>
    <div>
        <Button text="Click Me!" level="secondary" size="medium" shadow={true} />
    </div>
    <!-- the click of div can be stopped by button's stopPropagation -->
    <div role="presentation" onclick={() => {
        console.log("click from div")}}>
        <Button bind:this={buttonElement} text="Click Me!" level="primary" size="large" shadow={true} onLeftHover={() => console.log("Hovered on left side")} />
    </div>
</div>