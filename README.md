# Assignment 1 - Fours' Company:
# FLOW OF CONTROL & USAGE:

* Clone this repository

    ```
    git clone https://github.com/NamanJain8/assignment-1-fours-company.git
    ```

* Navigate to the directory.

    ```
    cd assignment-1-fours-company
    ```

* On the Server side, put together `server.c` and `files` directory. Compile the code and run the server.
    
    ```
    gcc server.c -o server
    ./server
    ```
    
* On the client side, individual `client.c` is sufficient. Compile the code and execute it (in another terminal) once the server is running. `client.c` expects input of the form "2 cars, 3 dogs and 4 trucks" etc. and passes it on to the server.


    ```
    gcc client.c -o client
    ./client
    2 cars, 3 dogs and 4 trucks
    ```

* `index.html` file is created on the server and the required images are sent to the client (in the current directory).

* A browser can now be used to render output (open the file `index.html`).
