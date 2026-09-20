# Hex and Parity Tools

Four command-line utilities in C, arranged as two encoder/decoder pairs — with each
decoder named as its encoder spelled backwards.

## The tools

| | Encoder | Decoder |
|---|---|---|
| **Hex** | `hex` | `xeh` |
| **Parity** | `parity` | `ytirap` |

**`hex` / `xeh`** — `hex` renders input as hexadecimal; `xeh` reverses it, parsing hex back
into the original bytes. Running input through both should return exactly what you started
with, which makes the pair self-testing.

**`parity` / `ytirap`** — `parity` adds a parity bit to each byte for error detection.
`ytirap` reads parity-encoded input, verifies each byte, and strips the bit back off. When
verification fails it reports `Corruption detected!` rather than silently returning wrong
data — the whole point of a parity scheme being that a single flipped bit is *noticed*.

## Usage

```bash
echo "hello" | ./hex
echo "68656c6c6f" | ./xeh
echo "hello" | ./parity | ./ytirap    # round-trips cleanly
```

## Building

```bash
gcc -Wall -Wextra -o hex hex.c
gcc -Wall -Wextra -o xeh xeh.c
gcc -Wall -Wextra -o parity parity.c
gcc -Wall -Wextra -o ytirap ytirap.c
```

Working at the bit level — masking, shifting, and counting set bits to compute parity — with
no library support beyond `stdio`.
