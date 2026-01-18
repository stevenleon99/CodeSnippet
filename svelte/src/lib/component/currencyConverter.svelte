<script lang="ts">
    import { rates } from "./dummy-rate";
    import { untrack } from "svelte";

    let baseValue: number | undefined = $state(1);
    let baseCurrency = $state('USD');
    let baseRates = $derived(rates[baseCurrency] || {});
    let targetCurrency = $state('EUR');
    let targetValue: number | undefined = $state();

    $effect(() => {
        targetValue = baseValue && baseRates[targetCurrency] && baseValue * baseRates[targetCurrency];
        console.log('calculating target value', untrack(() => targetValue));
    });

    $effect(() => {
        baseValue = targetValue && baseRates[baseCurrency] && targetValue / baseRates[targetCurrency];
        console.log('calculating base value', untrack(() => baseValue));
    });

    $inspect(baseRates);
</script>

<div class="wrapper">
    <div class="base">
        <input type="number" bind:value={() => baseValue, (value) => {
            if (value && value < 0) {
                baseValue = 1;
                return;
            } else {
                baseValue = value;
            }
        }} />
        <select bind:value={baseCurrency}>
            <option value="USD">USD</option>
            <option value="EUR">EUR</option>
            <option value="JPY">JPY</option>
        </select>
        <input type="number" bind:value={() => targetValue, (value) => {
            if (value && value < 0) {
                targetValue = 1;
                return;
            } else {
                targetValue = value;
            }
        }} />
        <select bind:value={targetCurrency}>
            <option value="USD">USD</option>
            <option value="EUR">EUR</option>
            <option value="JPY">JPY</option>
        </select>
    </div>
</div>