---
title: Transformer
description: PyTorch implementation of the original Transformer (Attention Is All You Need).
---

PyTorch implementation of the original Transformer paper by [Vaswani et al.](https://arxiv.org/abs/1706.03762).

## What are Transformers?

Transformers were originally proposed in the seminal paper *Attention Is All You Need*. The main idea is that you don't need recurrent or convolutional layers — a simple architecture coupled with attention is highly powerful. This gives **better long-range dependency modeling** and the architecture is highly **parallelizable**.

## Features

- Well-commented PyTorch implementation
- Interactive `playground.py` with visualizations of positional encodings, learning rate schedules, and label smoothing
- Trained on IWSLT dataset for English-German and German-English translation
- Attention visualization capabilities

## Setup

1. `git clone https://github.com/gordicaleksa/pytorch-original-transformer`
2. Run `conda env create` from project directory
3. Run `activate pytorch-transformer`

## Usage

### Training

```bash
python training_script.py --batch_size 1500 --dataset_name IWSLT --language_direction G2E
```

### Inference

```bash
python translation_script.py --source_sentence "Ich bin ein guter Mensch" --model_name iwslt_g2e --dataset_name IWSLT --language_direction G2E
```

## Results

| Model | BLEU Score | Dataset |
|-------|-----------|---------|
| EN-DE | 27.8 | IWSLT val |
| DE-EN | 33.2 | IWSLT val |
