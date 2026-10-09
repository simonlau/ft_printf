# memmove

> Sources: Michael Kerrisk, 2026-08-14
> Raw: ../../raw/string-functions/2026-08-10-memmove-3.md
> Updated: 2026-09-28

## Overview

The `memmove()` function copies `n` bytes from one memory area to another, correctly handling overlapping memory areas. It is part of the Standard C library (`<string.h>`) and is thread-safe.

## Description

`memmove()` is similar to `memcpy()`, but the memory areas may overlap. The function is standardized in C11 and POSIX.1-2008, with historical roots in C89, SVr4, and 4.3BSD.

Key points:
- Copies `n` bytes from `src` to `dest`
- Memory areas may overlap (unlike `memcpy`)
- Returns a pointer to `dest`
- Thread-safe (MT-Safe)
- Part of the Standard C library (`libc`, `-lc`)
- Includes `<string.h>`
- Preferred over `memcpy()` when overlap is possible

## Overlap handling

`memmove()` picks its copy direction from the relative positions of `dest` and `src`, so that no source byte is overwritten before it has been read:

- **`dest < src`** (destination at a lower address): copy **forward**, from the first byte. Each write lands at a lower address than the bytes still to be read.
- **`dest > src`** (destination at a higher address): copy **backward**, from the last byte. Each write lands at a higher address than the bytes still to be read.
- **`dest == src` or `n == 0`**: nothing to do; return `dest`.

```mermaid
flowchart TD
    Start([⚙️ memmove dest, src, n]) --> Zero{n == 0 or dest == src ?}
    Zero -->|Yes| Done([✅ Return dest — nothing to do])
    Zero -->|No| Overlap{dest < src ?}
    Overlap -->|Yes — dest before src| Forward[Copy forward: first byte → last]
    Overlap -->|No — dest after src| Backward[Copy backward: last byte → first]
    Forward --> Copy[Copy n bytes in the chosen direction]
    Backward --> Copy
    Copy --> Return([✅ Return dest])

    classDef startEnd fill:#E6E6FA,stroke:#333,stroke-width:2px,color:darkblue
    classDef process fill:#90EE90,stroke:#333,stroke-width:2px,color:darkgreen
    classDef decision fill:#FFD700,stroke:#333,stroke-width:2px,color:black

    class Start,Done,Return startEnd
    class Forward,Backward,Copy process
    class Zero,Overlap decision
```

## Overlapping examples

**Case 1 — `dest` after `src` (shift right), copied backward:**

```c
char buf[] = "abcdef";
memmove(buf + 2, buf, 4);
/* buf is now "ababcd" */
```

```mermaid
flowchart TD
    subgraph B["Before — memmove(buf + 2, buf, 4)"]
        direction LR
        B0["0: a"] --- B1["1: b"] --- B2["2: c"] --- B3["3: d"] --- B4["4: e"] --- B5["5: f"] --- B6["6: ∅"]
    end
    subgraph A["After — backward copy"]
        direction LR
        A0["0: a"] --- A1["1: b"] --- A2["2: a"] --- A3["3: b"] --- A4["4: c"] --- A5["5: d"] --- A6["6: ∅"]
    end
    B3 -->|1st| A5
    B2 -->|2nd| A4
    B1 -->|3rd| A3
    B0 -->|4th| A2

    classDef before fill:#87CEEB,stroke:#333,stroke-width:2px,color:darkblue
    classDef after fill:#90EE90,stroke:#333,stroke-width:2px,color:darkgreen
    classDef changed fill:#FFD700,stroke:#333,stroke-width:2px,color:black

    class B0,B1,B2,B3,B4,B5,B6 before
    class A0,A1,A6 after
    class A2,A3,A4,A5 changed
```

Backward copy: `buf[5]=buf[3]='d'`, `buf[4]=buf[2]='c'`, `buf[3]=buf[1]='b'`, `buf[2]=buf[0]='a'`. A forward copy here would clobber live source bytes and yield `"ababab"` instead.

**Case 2 — `dest` before `src` (shift left), copied forward:**

```c
char buf[] = "abcdef";
memmove(buf, buf + 2, 4);
/* buf is now "cdefef" */
```

```mermaid
flowchart TD
    subgraph B["Before — memmove(buf, buf + 2, 4)"]
        direction LR
        B0["0: a"] --- B1["1: b"] --- B2["2: c"] --- B3["3: d"] --- B4["4: e"] --- B5["5: f"] --- B6["6: ∅"]
    end
    subgraph A["After — forward copy"]
        direction LR
        A0["0: c"] --- A1["1: d"] --- A2["2: e"] --- A3["3: f"] --- A4["4: e"] --- A5["5: f"] --- A6["6: ∅"]
    end
    B2 -->|1st| A0
    B3 -->|2nd| A1
    B4 -->|3rd| A2
    B5 -->|4th| A3

    classDef before fill:#87CEEB,stroke:#333,stroke-width:2px,color:darkblue
    classDef after fill:#90EE90,stroke:#333,stroke-width:2px,color:darkgreen
    classDef changed fill:#FFD700,stroke:#333,stroke-width:2px,color:black

    class B0,B1,B2,B3,B4,B5,B6 before
    class A4,A5,A6 after
    class A0,A1,A2,A3 changed
```

Forward copy: `buf[0]=buf[2]='c'`, `buf[1]=buf[3]='d'`, `buf[2]=buf[4]='e'`, `buf[3]=buf[5]='f'`.

**Case 3 — identical pointers (no-op):**

```c
char buf[] = "abcdef";
memmove(buf, buf, 4);
/* buf is unchanged: "abcdef" */
```

## Non-overlapping examples

When the regions do not overlap, no source byte can be overwritten before it is read, so the copy direction is irrelevant.

**Case 4 — `dest` after `src` with a gap:**

```c
char buf[] = "abcdefg";
memmove(buf + 4, buf, 3);
/* buf is now "abcdabc" */
```

```mermaid
flowchart TD
    subgraph B["Before — memmove(buf + 4, buf, 3)"]
        direction LR
        B0["0: a"] --- B1["1: b"] --- B2["2: c"] --- B3["3: d"] --- B4["4: e"] --- B5["5: f"] --- B6["6: g"] --- B7["7: ∅"]
    end
    subgraph A["After — no overlap, any direction"]
        direction LR
        A0["0: a"] --- A1["1: b"] --- A2["2: c"] --- A3["3: d"] --- A4["4: a"] --- A5["5: b"] --- A6["6: c"] --- A7["7: ∅"]
    end
    B0 --> A4
    B1 --> A5
    B2 --> A6

    classDef before fill:#87CEEB,stroke:#333,stroke-width:2px,color:darkblue
    classDef after fill:#90EE90,stroke:#333,stroke-width:2px,color:darkgreen
    classDef changed fill:#FFD700,stroke:#333,stroke-width:2px,color:black

    class B0,B1,B2,B3,B4,B5,B6,B7 before
    class A0,A1,A2,A3,A7 after
    class A4,A5,A6 changed
```

**Case 5 — `dest` before `src` with a gap:**

```c
char buf[] = "abcdefg";
memmove(buf, buf + 4, 3);
/* buf is now "efgdefg" */
```

```mermaid
flowchart TD
    subgraph B["Before — memmove(buf, buf + 4, 3)"]
        direction LR
        B0["0: a"] --- B1["1: b"] --- B2["2: c"] --- B3["3: d"] --- B4["4: e"] --- B5["5: f"] --- B6["6: g"] --- B7["7: ∅"]
    end
    subgraph A["After — no overlap, any direction"]
        direction LR
        A0["0: e"] --- A1["1: f"] --- A2["2: g"] --- A3["3: d"] --- A4["4: e"] --- A5["5: f"] --- A6["6: g"] --- A7["7: ∅"]
    end
    B4 --> A0
    B5 --> A1
    B6 --> A2

    classDef before fill:#87CEEB,stroke:#333,stroke-width:2px,color:darkblue
    classDef after fill:#90EE90,stroke:#333,stroke-width:2px,color:darkgreen
    classDef changed fill:#FFD700,stroke:#333,stroke-width:2px,color:black

    class B0,B1,B2,B3,B4,B5,B6,B7 before
    class A3,A4,A5,A6,A7 after
    class A0,A1,A2 changed
```

**Case 6 — `n == 0`:** nothing is copied; `dest` is returned unchanged.
