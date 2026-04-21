---
title: Inline Function
description: C++ inline function and header-only library patterns.
---

C++ inline function and header-only library patterns.

## Contents

- **func.hpp** - Header-only function declarations
- **func-inl.hpp** - Inline implementation file (convention: `-inl.hpp` suffix)

## Pattern

This demonstrates the common C++ pattern of separating interface (`func.hpp`) and inline implementation (`func-inl.hpp`), which is included at the end of the header file for template and inline code organization.
