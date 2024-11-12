<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Libft - 1337 Cursus</title>
</head>
<body>

<h1>Libft - 1337 Cursus 🛠️</h1>
<p>Welcome to my <code>libft</code> project! This project was developed as part of the 1337 curriculum at Bengrir, following the <a href="https://www.42.fr/">42 School</a> methodology. <code>libft</code> is a personal library of C functions that mimic standard C library functions, as well as additional utilities useful for future projects.</p>

<h2>Table of Contents</h2>
<ul>
  <li><a href="#about-the-project">About the Project</a></li>
  <li><a href="#features">Features</a></li>
  <li><a href="#installation">Installation</a></li>
  <li><a href="#usage">Usage</a></li>
  <li><a href="#project-structure">Project Structure</a></li>
  <li><a href="#contributing">Contributing</a></li>
  <li><a href="#license">License</a></li>
</ul>

<h2 id="about-the-project">About the Project</h2>
<p>The <code>libft</code> project is a foundational assignment in the 1337 curriculum. The goal is to create a library in C that reimplements several functions from the standard C library (<code>&lt;stdlib.h&gt;</code>, <code>&lt;string.h&gt;</code>, etc.) and adds new utility functions. This project strengthens understanding of memory management, pointers, and function implementation, laying a strong foundation for more advanced projects.</p>

<h2 id="features">Features</h2>
<ul>
  <li><strong>Standard Library Functions</strong>: Re-implemented functions like <code>ft_strlen</code>, <code>ft_strcpy</code>, <code>ft_atoi</code>, and more.</li>
  <li><strong>Memory Management</strong>: Includes functions like <code>ft_memset</code>, <code>ft_memcpy</code>, <code>ft_bzero</code>, etc.</li>
  <li><strong>String Manipulation</strong>: Functions for string operations, including <code>ft_strchr</code>, <code>ft_strncmp</code>, <code>ft_strdup</code>, and others.</li>
  <li><strong>Additional Utility Functions</strong>: Helper functions designed for various programming needs.</li>
</ul>

<h2 id="installation">Installation</h2>
<ol>
  <li><strong>Clone the Repository</strong>:
    <pre><code>git clone https://github.com/ACH4Q/1337-Cursus.git
cd 1337-Cursus/libft
</code></pre>
  </li>
  <li><strong>Compile the Library</strong>:<br>
  Run the <code>Makefile</code> to compile the library:
    <pre><code>make</code></pre>
  </li>
  <li><strong>Include in Your Project</strong>:<br>
  After compiling, link <code>libft.a</code> with your project files:
    <pre><code>#include "libft.h"</code></pre>
  </li>
</ol>

<h2 id="usage">Usage</h2>
<p>After including <code>libft.a</code> and <code>libft.h</code> in your project, you can call any of the implemented functions as you would with standard C library functions.</p>
<pre><code>#include "libft.h"

int main() {
    char str[] = "Hello, world!";
    ft_putstr(str);  // Custom function to print a string
    return 0;
}
</code></pre>

<h2 id="project-structure">Project Structure</h2>
<ul>
  <li><code>libft.h</code> - Header file with function prototypes.</li>
  <li><code>src/</code> - Directory containing the source code files for each function.</li>
  <li><code>Makefile</code> - Script to compile the library.</li>
</ul>

<h2 id="contributing">Contributing</h2>
<p>If you'd like to contribute to this project, please fork the repository and submit a pull request. Any additions or improvements are welcome!</p>

<h2 id="license">License</h2>
<p>This project is licensed under the MIT License. See the <a href="LICENSE">LICENSE</a> file for details.</p>

</body>
</html>
