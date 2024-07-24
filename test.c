// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/stat.h>
// #include <unistd.h>

// // Function to print the file size in blocks
// void print_file_size_in_blocks(const char *file_path) {
//     struct stat file_stat;
    
//     // Get file status
//     if (stat(file_path, &file_stat) == 0) {
//         // Print size in blocks (st_blocks gives the number of 512-byte blocks)
//         printf("Size: %ld blocks\n", (long)file_stat.st_blocks);
//     } else {
//         perror("stat");
//     }
// }

// int main(int argc, char *argv[]) {
//     if (argc != 2) {
//         fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
//         return EXIT_FAILURE;
//     }

//     print_file_size_in_blocks(argv[1]);

//     return EXIT_SUCCESS;
// }