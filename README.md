  # 🧠 Philosophers  
  **"I never thought philosophy would be so deadly." — developed by [@ifrankerem](https://github.com/ifrankerem)**  

  The **Philosophers** project is a multithreading simulation written in C.  
  It models the famous *Dining Philosophers Problem* — a classic synchronization challenge that tests your understanding of **threads**, **mutexes**, and **shared resources**.

  The project demonstrates how concurrent processes interact safely while avoiding **deadlocks**, **data races**, and **starvation**.

  ---

  ## 🧩 What Is This Project About?

  Imagine a group of philosophers sitting around a table with forks between them.  
  Each philosopher alternates between **thinking**, **eating**, and **sleeping** —  
  but to eat, they must pick up **two forks** (one on the left, one on the right).  
  Since the number of forks is limited, this creates a concurrency problem.

  Your task:  
  Build a system where philosophers can eat without conflicts, starvation, or deadlocks — using threads and mutexes.

  ---

  ## ⚙️ Features

  ✅ Real-time simulation of multiple philosophers  
  ✅ Thread-based concurrency with **pthread**  
  ✅ Mutex-based fork management  
  ✅ Precise timestamped logging  
  ✅ Thread-safe output  
  ✅ Optional parameter to define required number of meals  
  ✅ Clean handling of philosopher death conditions  
  ✅ No global variables — all data encapsulated in structs  

  ---

  ## 🧰 Installation & Setup

  ### 1️⃣ Clone the repository
  ```bash
  git clone https://github.com/iarslan/philosophers.git
  cd philosophers
  ```

  ### 2️⃣ Build the project
  Make sure you have GCC and Make installed.  
  Then compile the program:
  ```bash
  make
  ```

  ### 3️⃣ Run the simulation
  ```bash
  ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
  ```

  #### Example
  ```bash
  ./philo 5 800 200 200
  ```

  ➜ Runs a simulation with 5 philosophers who die if they don’t eat within 800 ms,  
  take 200 ms to eat, and 200 ms to sleep.

  #### Example with required meal count
  ```bash
  ./philo 5 800 200 200 5
  ```
  ➜ The simulation stops when each philosopher has eaten 5 times.

  ---

  ## 💬 Example Output

  ```
  0 1 is thinking
  10 1 has taken a fork
  12 1 has taken a fork
  13 1 is eating
  213 1 is sleeping
  414 1 is thinking
  601 3 died
  ```

  Each log entry includes:
  - A **timestamp** (in milliseconds)
  - The **philosopher ID**
  - The **state**: taking a fork, eating, sleeping, thinking, or dying

  ---

  ## 🧠 Understanding the Rules

  - Each philosopher is represented by a **thread**.  
  - Each fork is protected by a **mutex** to prevent simultaneous access.  
  - The simulation stops when:
    - A philosopher dies  
    - (Optional) All philosophers have eaten the required number of times  
  - All logs are **thread-safe** — no overlapping messages.  
  - Death messages appear within 10 ms of the actual event.

  ---

  ## 🌟 Bonus (Optional)

  The bonus version (`philo_bonus`) uses **processes** and **semaphores** instead of threads and mutexes.

  - Each philosopher becomes a **separate process**  
  - Forks are managed through a shared semaphore  
  - All philosophers can safely synchronize through IPC  
  - No shared memory — everything relies on semaphores  

  ---

  ## 🔍 Example Visualization

  ![Dining Philosophers Example](https://upload.wikimedia.org/wikipedia/commons/7/7b/An_illustration_of_the_dining_philosophers_problem.png)

  *(Illustration: Five philosophers alternating between thinking, eating, and waiting for forks.)*

  ---

  ## 💡 Learning Outcomes

  - Mastering **thread creation** and synchronization (`pthread_create`, `pthread_mutex_*`)  
  - Managing **concurrent access** to shared resources  
  - Avoiding **deadlocks** and **race conditions**  
  - Understanding **precise timing** with `gettimeofday()` and `usleep()`  
  - Structuring thread-safe simulations  

  ---

  ## 🎥 Project Demo
  Check out the full video demonstration on YouTube 👇  
  ▶️ [Watch on YouTube](https://www.youtube.com/watch?v=w3of0xvm7Ck)

  ---
  ## 📜 License

  This project is part of the **42 School curriculum** and created purely for educational purposes.  
  You are free to read, learn, and experiment with it — but not to reuse for evaluation submissions.

  ---

  🧑‍💻 *Developed by [@ifrankerem](https://github.com/ifankerem)*
