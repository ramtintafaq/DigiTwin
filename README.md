# DigiTwin – Sensor Database (PostgreSQL + C++)

This project is part of a university group assignment. It implements a C++ backend that connects to a PostgreSQL database to manage structures, buildings, and (soon) sensor data.

## 🧰 Prerequisites

- PostgreSQL (v14+)
- C++20-compatible compiler (Clang or GCC)
- CMake
- CLion (recommended)

---

## ⚙️ Setup Instructions

### 1. 🧑‍💻 PostgreSQL Setup

1. Start your PostgreSQL server
    ```bash
    brew services start postgresql@14
    ```

2. Create a user and database:
    ```bash
    createdb digitwin
    createuser your_username
    psql -d postgres
    ```

3. Inside `psql`, run:
    ```sql
    ALTER USER your_username WITH ENCRYPTED PASSWORD 'your_password';
    GRANT ALL PRIVILEGES ON DATABASE digitwin TO your_username;
    ```

> Replace `your_username` and `your_password` with your own info.

---

### 2. 🔐 Create `db.conf`

In the root folder of the project (same level as `main.cpp`), create a file called `db.conf`:

```
host=localhost
dbname=digitwin
user=your_username
password=your_password
```

⚠️ This file is ignored by Git and never pushed.

---

### 3. 🛠 Build and Run

```bash
cmake -B build
cmake --build build
./build/TeamP
```

You should see:

```
Connected to PostgreSQL successfully!
Buildings table created successfully.
Structures table created successfully.
```

