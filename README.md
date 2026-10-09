<div align="center">

# 🧠 Philosophers

**The dining philosophers problem, solved in C with threads and mutexes — no philosopher may starve.**

![Language](https://img.shields.io/badge/language-C-00599C?style=flat-square)
![42](https://img.shields.io/badge/42-Common%20Core-000000?style=flat-square)
![Concurrency](https://img.shields.io/badge/pthreads-%2B%20semaphores-8A2BE2?style=flat-square)
![Norminette](https://img.shields.io/badge/norm-42%20standard-2b9348?style=flat-square)
![Stars](https://img.shields.io/github/stars/ifrankerem/Philosophers?style=flat-square)

</div>

> *"I never thought philosophy would be so deadly."*

---

## 📋 Table of Contents

- [About](#about)
- [The Problem](#the-problem)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Output Format](#output-format)
- [Implementation](#implementation)
- [Bonus](#bonus)
- [Learning Outcomes](#learning-outcomes)
- [Demo](#demo)
- [Author](#author)

---

## 📖 About

**Philosophers** is a multithreading simulation written in **C** that models the
famous *Dining Philosophers Problem* — philosophers alternating between
thinking, eating and sleeping at a table where each fork is a contested
resource.

The job is to run the table with **no deadlocks, no data races and no
starvation**, using `pthread` and mutexes (threads) or processes and
semaphores (bonus).

---

## 🍽 The Problem

- `N` philosophers sit at a round table; a fork lies between each pair.
- A philosopher needs **both** adjacent forks to eat.
- Between two philosophers there is only **one** fork — so two neighbours can
  never eat at the same time.
- Simulation stops when a philosopher **dies** (no meal in time) or, if the
  optional argument is given, when everyone has eaten enough.

---

## 🚀 Getting Started

**Prerequisites**

- `gcc`, `make`

**Build**

```sh
git clone https://github.com/ifrankerem/Philosophers.git
cd Philosophers
make            # builds philo and philo_bonus
```

---

## 💻 Usage

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep \
       [number_of_times_each_philosopher_must_eat]
```

| Argument | Meaning |
|---|---|
| `number_of_philosophers` | how many sit at the table |
| `time_to_die` | ms a philosopher survives without eating |
| `time_to_eat` | ms a meal takes |
| `time_to_sleep` | ms a nap takes |
| `[number_of_times_each_philosopher_must_eat]` | optional — simulation stops once reached |

**Example**

```sh
./philo 5 800 200 200
./philo 5 800 200 200 5      # stops after everyone has eaten five times
```

---

## 📜 Output Format

```text
0 1 is thinking
10 1 has taken a fork
12 1 has taken a fork
13 1 is eating
213 1 is sleeping
414 1 is thinking
601 3 died
```

Each line: timestamp in milliseconds, philosopher id (starting at 1), and state.

---

## 🔧 Implementation

- Each philosopher is a **thread**; each fork is a **mutex**.
- Fork acquisition is staggered by parity to break the deadlock cycle, and
  locks are released in the same order they were taken.
- Death is monitored by a dedicated scanner with its own timer.
- Every state change writes through one print mutex, so lines never interleave.
- Timing uses `gettimeofday` and a precision sleep helper rather than a bare
  `usleep`, so death messages stay within the 10 ms tolerance.

---

## 🎉 Bonus

`philo_bonus` replaces threads and mutexes with **processes** and
**semaphores**:

- Each philosopher is a forked process.
- Every fork is a named semaphore.
- Shared access goes through semaphore-protected semaphores alone.
- All state lives in shared memory with no global variables outside the
  program state struct.

---

## 🧩 Game Loop Rules

| Action | Rule |
|---|---|
| Eat | hold both forks, sleep for `time_to_eat`, release both |
| Death | no meal for more than `time_to_die` |
| Simulation ends | a death occurs, or the optional meal count is met |
| Output order | chronological, all timestamps in milliseconds |

---

## 🧠 Learning Outcomes

- Thread creation and join, and the lifecycle of a `pthread`.
- Correct use of `pthread_mutex_*` to protect shared state.
- Detecting and preventing deadlock and starvation.
- Precise timing with `gettimeofday` and a tuned sleep.
- Writing output paths that stay thread-safe under load.

---

## 🎓 Demo

▶️ [Watch on YouTube](https://www.youtube.com/watch?v=w3of0xvm7Ck)

---

## 👤 Author

**İrfan Kerem Arslan** — [@ifrankerem](https://github.com/ifrankerem)

---

## 📄 License

Built for the **42 Common Core** curriculum. Shared for learning and portfolio
purposes.

---

## 🙏 Acknowledgements

- [awesome-readme](https://github.com/matiassingers/awesome-readme) — structure inspiration for this README