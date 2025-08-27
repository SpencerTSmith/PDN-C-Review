#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int multiply_and_add_numbers(int accumulate, int x, int y)
{
  int result = accumulate + (x * y);

  return result;
}

void pass_by_value(int value)
{
  value = -9999;
}

void pass_by_pointer(int *value)
{
  // We dereference with * ... confusing but thats the way it is
  *value = -9999;
}

// int* make_array_with_constant(int n) {
//     int arr[10];
//     for (int i = 0; i < 10; i++) {
//         arr[i] = n;
//     }
//
//     // Uh oh
//     return arr;
// }

void scale_array(int *array, int array_length, int scale_factor)
{
  for (int i = 0; i < array_length; i++)
  {
    array[i] *= scale_factor;
  }
}

struct Int_Array_Slice
{
  int *data;
  int count;
};

void do_something_with_slice_struct(struct Int_Array_Slice slice)
{
  for (int i = 0; i < slice.count; i++)
  {
    slice.data[i] *= (i * 2);
  }
}

// Maybe a little more ergonomic:
/*
typedef struct Int_Array_Slice_t Int_Array_Slice;
struct Int_Array_Slice_t
{
int *data;
int count;
};
void do_something_with_slice(Int_Array_Slice slice);
*/

int main(int argc, char **argv)
{
  //
  // Pointers
  //
  /*
  int x = 1;
  printf("The value of X is: %d\n", x);

  int *ptr_to_x = &x;
  printf("The address of X is: %p\n", ptr_to_x);

  int dereference_x = *ptr_to_x;
  printf("And dereferenced the pointer is: %d\n", dereference_x);
  */

  // int *pointer_to_null = NULL;
  // printf("And just a quick null dereference: %d", *pointer_to_null); // Uh oh

  /*
  // Helpful NULL check idiom
  int *pointer_to_null = NULL;
  if (pointer_to_null != NULL)
  {
     //Then do something with it
  }
  // Or
  if (pointer_to_null)
  {
    // Then do something with it
  }
  */


  //
  // Arrays
  //
  /*
  {
    int array[4] = {0, 1, 2, 3};

    for (int i = 0; i < 4; i++)
    {
    printf("Array at [%d] is %d\n", i, array[i]);
    }

    printf("And the value of array is? %p\n", array);
  }
  */

  // What do arrays give us? (Nice pointer arithmetic syntax)
  /*
  {
    int array[4] = {0, 1, 2, 3};

    for (int i = 0; i < 4; i++)
    {
      int array_access = array[i];
      int pointer_arithmetic_access = *(array + i); // Increment the pointer by 1, and dereference
      printf("Array[%d] is %d == %d\n", i, array[i], *(array + i));
    }
  }
  */

  //
  // Functions and Arguments
  //
  /*
  {
    int accumulate = 0;
    int x = 2;
    int y = 3;

    int mac = multiply_and_add_numbers(accumulate, x, y);
    printf("The result of multiply_and_add_numbers is %d\n", mac);
  }
  */

  /*
  {
    int value = 100;
    pass_by_value(value);

    printf("The result of pass_by_value is %d\n", value);
  }
  */

  /*
  {
    int value = 100;
    pass_by_pointer(&value);

    printf("The result of pass_by_pointer is %d\n", value);
  }
  */

  //
  // Stack memory
  //
  /*
  {
    int *array = make_array_with_constant(10);

    for (int i = 0; i < 10; i++)
    {
      printf("What's in array[%d] = %d\n", i, array[i]);
    }
  }
  */

  // Common idiom for passing arrays to functions
  /*
  {
    #define LENGTH 4
    int array[LENGTH] = {0, 1, 2, 3};
    int scale_factor = 10;
    scale_array(array, LENGTH, scale_factor);

    for (int i = 0; i < LENGTH; i++)
    {
      printf("What's in array[%d] = %d\n", i, array[i]);
    }
  }
  */

  //
  // Dynamic allocation
  //
  /*
  {
    int length = 1024*1024*10;
    int array[length] = {};

    for (int i = 0; i < length; i++)
    {
      array[i] = 10 * i;
      printf("array[%d] is %d\n", i, array[i]);
    }
  }
  */

  /*
  {
    int length = 1024*1024*10;
    int *array = malloc(length * sizeof(int));

    for (int i = 0; i < length; i++)
    {
      array[i] = 10 * i;
      printf("array[%d] is %d\n", i, array[i]);
    }

    // Remember to free... sometimes (explain)
    free(array);
  }
  */

  //
  // Strings
  //
  // Remember to show the string in the executable
  // const char *message = "Hello from the code's data segment!";
  // printf("The data segment has a message:\n   %s\n", message);

  // Can't modify read only!
  // message[2] = 'n';

  // Not so fast
  // char *sneaky = (char *)message;
  // sneaky[2] = 'n';

  // How do functions know the end of a string if it's just a pointer?
  // Null terminated

  // Undefined behavior
  /*
  char stack_string[2] = {'h', 'i'};
  char poison[4] = {'X','X','X','X'}; // Uh oh
  printf("Stack string is %s ... wait what?\n", stack_string);
  */

  // Proper stack string
  /*
  char buffer[256] = {'h', 'i', ',', 't', 'h', 'e', 'r', 'e', '\0'}; // Overestimate memory requirement if you want
  printf("Buffer string is: %s\n", buffer);
  */

  // Or just use a string literal
  /*
  char literal_buffer[256] = "Hello!";
  printf("Buffer with literal is: %s\n", literal_buffer);
  */

  // Same applies for 'heap' allocated strings
  /*
  char *heap_buffer = calloc(256, sizeof(char)); // Explain calloc too
                                                 //
  const char *message = "Hello from somewhere in memory!";
  memcpy(heap_buffer, message, strlen(message)); // Note the use of strlen
                                                 //
  printf("Heap buffer is\n   %s\n", heap_buffer);

  free(heap_buffer); // Remember!
  */

  //
  // Structs
  //
  /*
  int array[4] = {0, 1, 2, 3};
  struct Int_Array_Slice slice =
  {
    .data  = array,
    .count = 4,
  };
  do_something_with_slice_struct(slice);

  for (int i = 0; i < slice.count; i++)
  {
    printf("Slice at [%d] is %d\n", i, slice.data[i]);
  }
  */

  //
  // File Handling
  //

  // NOTE: This is kind of the old school way... in the real world anytime you read a file in... you read the whole thing into memory
  // Not just traversing via the stdlib FILE*... I can show a demo of that if needed, But this will work for simple stuff

  /*
  FILE *input_file = fopen("input.txt", "r");

  char buffer[256] = {0};
  while (fgets(buffer, sizeof(buffer), input_file)) // Remember to explain why this conditional works
  {
    printf("%s", buffer);
  }

  fclose(input_file); // Remember!
  */

  /*
  FILE *output_file = fopen("output.txt", "w");

  const char *message_to_file = "Hello file!";
  fprintf(output_file, "%s", message_to_file); // Notice... (f)printf?

  fclose(output_file); // Remember!
  */

  // NOTE:
  // FILE*  is a stream! and when you say printf you are doing shorthand for writing to the STDOUT stream
  /*
  fprintf(stdout, "Same thing!\n");
  printf("Same thing!\n");
  */

  //
  // Entrypoint Arguments
  //
  /*
  for (int i = 0; i < argc; i++)
  {
    printf("%s\n", argv[i]);
  }
  */

  // You can imagine reading these args in and changing the way
  // the program runs based on the values of these arguments

  /*
  // atoi == Ascii to Integer
  int length = atoi(argv[1]); // Probably want something more robust in non trivial program
  int *runtime_sized_array = calloc(length, sizeof(int));

  printf("We have an array of length %d, determined at runtime\n", length);
  for (int i = 0; i < length; i++)
  {
    printf("Runtime array[%d] is %d\n", i, runtime_sized_array[i]);
  }
  */

  // NOTE: Might not have enough time to cover header files, function declarations, etc

  // Most of the other language constructs work like you expect
  // if else, switch statements, etc

  // Questions?
}
