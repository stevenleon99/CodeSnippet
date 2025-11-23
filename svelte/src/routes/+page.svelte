<script lang="ts">
    const people = {
        firstName: 'John',
        lastName: 'Doe',
        occupations: [],
        get fullName() {
            return `${this.firstName} ${this.lastName}`; // custom getter function
        },
        set fullName(name: string) {                     // custom setter function
            const parts = name.split(' ');
            this.firstName = parts[0];
            this.lastName = parts[1];
        },
        set occupation(value: String) {
            this.occupations.push(value);
            console.log(this.occupations);
        }
    };
    console.log(people.fullName);
    people.fullName = 'Jane Smith';
    console.log(people.fullName);
    people.occupation = 'Developer';
    people.occupation = 'Designer';

    const handler = {
        get(people, prop) {
            return prop in people ? people[prop] : 'NAN'; // intercept property access
        },
        set(people, prop, value) {
            console.log(`Setting ${prop} to ${value}`);
            people[prop] = value;
            return true;
        }
    };
    // use new for constructors that are not callable as plain functions
    const proxy = new Proxy(people, handler); // create a proxy to access the object via proxy
    proxy.firstName = 'FirstName Changed'; // Intercepted by proxy
    console.log(proxy.firstName); // Accessing via proxy

</script>



<style>
    :global {
            body {
            background-color: #222;
        }
    }
</style>