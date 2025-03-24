## 🚀 How to Run

### 📋 Prerequisites

- C++20 compiler (`g++`, `clang++`, etc.)
- SQLite3 installed:
  ```bash
  brew install sqlite3
  ```
- CMake (CLion recommended or via terminal)

---

### 🛠️ Build Instructions (with CMake)

#### 1. Clone the repository

```bash
git clone https://github.com/ramtintafaq/DigiTwin.git
cd DigiTwin
```

#### 2. Create build directory

```bash
mkdir build && cd build
cmake ..
make
```

#### 3. Run the app

```bash
./DigiTwin
```

You should see:

```
Database opened successfully.
Buildings table created.
Structures table created.
Sensors table created.
```

---

### 🧪 View the Database

You can inspect the database file (`sensor_database.db`) using:

```bash
sqlite3 sensor_database.db
```

Inside the SQLite prompt:

```sql
.tables
SELECT * FROM buildings;
```

Or use a GUI like [DB Browser for SQLite](https://sqlitebrowser.org).

---

## 🧑‍💻 Folder Structure

```
.
├── include/         # Header files
├── src/             # Implementation files
├── main.cpp         # Main entry point
├── CMakeLists.txt   # Build config
└── sensor_database.db (runtime generated)
```
