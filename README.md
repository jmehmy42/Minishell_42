# Minishell

Welcome to **Minishell** — a lightweight, educational shell implementation in C, inspired by the UNIX shell. This project was crafted as part of the 42 curriculum to deepen understanding of process management, parsing, and command execution in a UNIX environment.

---

## 🚀 Features

- **Built-in commands:**  
  - `cd`, `echo`, `pwd`, `export`, `unset`, `env`, `exit`
- **External command execution**
- **Pipes & Redirections:**  
  - Support for `|`, `>`, `<`, `>>`
- **Environment variable management**
- **Signal handling**  
  - Gracefully handles `Ctrl+C`, `Ctrl+D`, `Ctrl+\`
- **Error messages and status codes**
- **Minimal memory leaks** (Valgrind-friendly)

---

## 📦 Getting Started

### Prerequisites

- GCC or Clang
- Make

### Build and Run

```bash
make
./minishell
```

---

## 🛠️ Usage

Type commands as you would in a standard shell:

```bash
minishell$ echo Hello, Minishell!
Hello, Minishell!

minishell$ export NAME=42
minishell$ echo $NAME
42
```

Supports chaining with pipes and using redirections:

```bash
minishell$ ls -l | grep minishell > result.txt
```

---

## 📚 Project Structure

- **src/** — Source files
- **include/** — Header files
- **Makefile** — Build instructions

---

## 🧑‍💻 Authors

- [jmehmy42](https://github.com/jmehmy42)
- [Kevin](https://github.com/Kevinwmiguel)

---

## 🎓 About

Minishell was developed as part of the [42 School](https://42.fr/en/homepage/) curriculum, focusing on reproducing essential shell features from scratch using C and the UNIX API.

---

## 📄 License

This project is for educational purposes only.

---

## 🙌 Acknowledgements

Special thanks to the 42 Network and community for guidance and resources!

---

> _“The shell is both a command interpreter and a programming language.”_
