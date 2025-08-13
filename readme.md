# Neofetch Clone

This project is a clone of the popular system information tool, Neofetch. It displays system information in a visually appealing way using ASCII art logos.

## Features

- Display OS information
- Display Kernel information
- Display system uptime
- Display CPU information
- Display memory information
- Display ASCII art logos for different distributions

## Project Structure

```
neofetch/
├── logos/
│   └── ubuntu.txt
├── src/
│   ├── ascii_art.cpp
│   ├── ascii_art.h
│   ├── main.cpp
│   ├── system_info.cpp
│   └── system_info.h
```

## How to Build and Run

1. **Clone the repository:**

    ```sh
    git clone https://github.com/MoB-369/neofetch.git
    cd neofetch
    ```

2. **Build the project:**

    ```sh
    make
    ```

3. **Run the executable:**

    ```sh
    make run
    ```
    To make it colorfull you can pipe it with `lolcat`.

    ```sh
        make run | lolcat
    ```
4. **Clean the build:**
    ```sh
    make clean
    ```
## Example Output

```
.-/+oossssoo+/-.           
        `:+ssssssssssssssssss+:`       
      -+ssssssssssssssssssyyssss+-     
    .ossssssssssssssssssdMMMNysssso.   
   /ssssssssssshdmmNNmmyNMMMMhssssss/  
  +ssssssssshmydMMMMMMMNddddyssssssss+ 
 /sssssssshNMMMyhhyyyyhmNMMMNhssssssss/
.ssssssssdMMMNhsssssssssshNMMMdssssssss.
+sssshhhyNMMNyssssssssssssyNMMMysssssss+
ossyNMMMNyMMhsssssssssssssshmmmhssssssso
ossyNMMMNyMMhsssssssssssssshmmmhssssssso
+sssshhhyNMMNyssssssssssssyNMMMysssssss+
.ssssssssdMMMNhsssssssssshNMMMdssssssss.
 /sssssssshNMMMyhhyyyyhdNMMMNhssssssss/ 
  +sssssssssdmydMMMMMMMMddddyssssssss+  
   /ssssssssssshdmNNNNmyNMMMMhssssss/   
    .ossssssssssssssssssdMMMNysssso.    
      -+sssssssssssssssssyyyssss+-      
        `:+ssssssssssssssssss+:`       
            .-/+oossssoo+/-.

--------------------------------------------------------
OS: Linux
Kernel: 5.4.0-42-generic
Uptime: 5h 23m
CPU: Intel(R) Core(TM) i7-8550U CPU @ 1.80GHz
Memory: Total: 16384 kB Available: 12345 kB
```

## License

This project is licensed under the MIT License.
