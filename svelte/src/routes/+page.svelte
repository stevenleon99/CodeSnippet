<script lang="ts">
    import User from '$lib/component/user.svelte';
    import RandomNumber from '$lib/component/randomNumber.svelte';
	import Counter from '$lib/component/counter.svelte';
    import Button from '$lib/component/button.svelte';

    let firstname = $state('Steve');
    let lastname = $state('Josh');
    let fullName = $derived.by(() => `${firstname} ${lastname}`); // derived variable has memory (compared to function), which means it only updates onnce if two elements depend on it and its value doesn't change.
    let username = $state('xxxxxxxxxx');
    let src = 'https://cdn.pixabay.com/photo/2017/07/23/21/29/globus-2532875_1280.png';
    let bio = 'Hello, <b>this</b> is in bold';

    $effect(() => {
        if (username || firstname ) {
            console.log('username or firstname changed');
        }
    });
    // effect and effect.pre

</script>

<!-- $prop() is able to pass props to components from parent to child. -->
<User data="hello" />
<RandomNumber />


<input bind:value={username} />
<input bind:value={firstname} />
<input bind:value={lastname} />

<h1>{username || fullName}</h1>
<p>{@html bio}</p>

<Counter />
<div>
    <Button text = "start" level = "info" />
</div>


<style>
    h1{
        color:cornflowerblue;
    }
</style>