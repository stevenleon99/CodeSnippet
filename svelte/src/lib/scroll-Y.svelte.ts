import { browser } from "$app/environment";
import { createSubscriber } from "svelte/reactivity"
import { on } from "svelte/events";

class scrollY {
    #subscriber
    
    constructor() {
        this.#subscriber = createSubscriber((update) => {
            console.log("init");
            const off = on(window, "scroll", update);
            return () => {
                off();
                console.log("destroy" );
            };
        })
    }

    get current() {
        this.#subscriber();
        return browser ? window.scrollY : 0;
    }

    
}
