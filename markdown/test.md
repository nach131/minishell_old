# Test hacer en minishell

```bash
export uno dos tres=
```
```bash
export
```
Se declaran todas pero solo tres tiene valo vacio.

	declare -x uno
	declare -x dos
	declare -x tres=""
```bash
env
```
Solo esta tres con valor vacio en la lista de env

	tres=
---
