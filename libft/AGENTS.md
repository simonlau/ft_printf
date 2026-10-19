## Agent skills

### Issue tracker

Issues live as local markdown files under `.scratch/`. See `docs/agents/issue-tracker.md`.

### Triage labels

Default triage label vocabulary. See `docs/agents/triage-labels.md`.

### Domain docs

Single-context domain docs (`GLOSSARY.md` + `docs/adr/`). See `docs/agents/domain.md`.

### Pre-commit checks

Before committing, run `pre-commit install` once, then commit normally. The hooks run:

- **norminette** on root `.c`/`.h` files only (skips `tests/`).
- **`make test`** on every commit.

Run them manually with `pre-commit run --all-files`. See `.pre-commit-config.yaml`.
