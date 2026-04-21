// @ts-check
import { defineConfig } from 'astro/config';
import starlight from '@astrojs/starlight';

// https://astro.build/config
export default defineConfig({
	site: 'https://stevenleon99.github.io',
	base: '/CodeSnippet',
	integrations: [
		starlight({
			title: 'Code Snippets',
			description: 'A collection of code snippets across C, C++, Matlab, Python, CMake, Shell, PowerShell and more.',
			customCss: ['./src/styles/custom.css'],
			components: {
				Header: './src/components/Header.astro',
				SocialIcons: './src/components/SocialIcons.astro',
			},
			social: [
				{ icon: 'github', label: 'GitHub', href: 'https://github.com/stevenleon99/triviaCode' },
			],
			sidebar: [
				{
					label: 'Getting Started',
					items: [
						{ label: 'Introduction', slug: 'introduction' },
					],
				},
				{
					label: 'AI & Machine Learning',
					items: [
						{ label: 'AI Model Deploy Test', slug: 'ai_model_deploy_test' },
						{ label: 'Machine Learning', slug: 'machinelearnning' },
						{ label: 'Stable Baselines 3', slug: 'stablebaselines3' },
						{ label: 'Transformer', slug: 'transformer' },
					],
				},
				{
					label: 'Algorithms',
					items: [
						{ label: 'Algorithm', slug: 'algorithm' },
						{ label: 'Gravity Compensation', slug: 'gravitycompensation' },
					],
				},
				{
					label: 'C/C++ Development',
					items: [
						{ label: 'Boost', slug: 'boost' },
						{ label: 'CMake', slug: 'cmake' },
						{ label: 'Concurrency', slug: 'concurrency' },
						{ label: 'Eigen', slug: 'eigen' },
						{ label: 'Inline Function', slug: 'inline-function' },
						{ label: 'Singleton', slug: 'singleton' },
						{ label: 'Smart Pointer', slug: 'smartpointer' },
						{ label: 'Shared Memory', slug: 'sharememory' },
					],
				},
				{
					label: 'Web & Servers',
					items: [
						{ label: 'Docker', slug: 'docker' },
						{ label: 'Miniserver', slug: 'miniserver' },
						{ label: 'RabbitMQ', slug: 'rabbitmq' },
						{ label: 'Svelte', slug: 'svelte' },
					],
				},
				{
					label: 'Embedded & Systems',
					items: [
						{ label: 'STM32', slug: 'stm32' },
						{ label: 'dVRK Qt', slug: 'dvrk_qt' },
					],
				},
				{
					label: 'Scripting & Tools',
					items: [
						{ label: 'Git', slug: 'git' },
						{ label: 'Python', slug: 'python' },
						{ label: 'Rust', slug: 'rust' },
						{ label: 'Shell Script', slug: 'shellscript' },
						{ label: 'Windows Shell', slug: 'winsh' },
						{ label: 'Test Automation', slug: 'testautomation' },
					],
				},
				{
					label: 'Documentation',
					items: [
						{ label: 'LaTeX', slug: 'latex' },
						{ label: 'MATLAB', slug: 'matlab' },
					],
				},
			],
		}),
	],
});
