# 0x19. C - Stacks, Queues - LIFO, FIFO

<h2>Resources</h2>

<p><strong>Read or watch</strong>:</p>

<ul>
<li><a href="/rltoken/56-bDz7IrFgcH02EkGkB3w" title="Google" target="_blank">Google</a> </li>
<li><a href="/rltoken/9neX6gaN6DoA-ow1INgZqw" title="How do I use extern to share variables between source files in C?" target="_blank">How do I use extern to share variables between source files in C?</a> </li>
</ul>

<h2>Learning Objectives</h2>

<p>At the end of this project, you are expected to be able to <a href="/rltoken/S9hXXmjvT8hvNyFQLnSGug" title="explain to anyone" target="_blank">explain to anyone</a>, <strong>without the help of Google</strong>:</p>

<h3>General</h3>

<ul>
<li>What do LIFO and FIFO mean</li>
<li>What is a stack, and when to use it</li>
<li>What is a queue, and when to use it</li>
<li>What are the common implementations of stacks and queues</li>
<li>What are the most common use cases of stacks and queues</li>
<li>What is the proper way to use global variables</li>
</ul>

<h2>Requirements</h2>

<h3>General</h3>

<ul>
<li>Allowed editors: <code>vi</code>, <code>vim</code>, <code>emacs</code></li>
<li>All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c90</li>
<li>All your files should end with a new line</li>
<li>A <code>README.md</code> file, at the root of the folder of the project is mandatory</li>
<li>Your code should use the <code>Betty</code> style. It will be checked using <a href="https://github.com/holbertonschool/Betty/blob/master/betty-style.pl" title="betty-style.pl" target="_blank">betty-style.pl</a> and <a href="https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl" title="betty-doc.pl" target="_blank">betty-doc.pl</a></li>
<li>You allowed to use a maximum of one global variable</li>
<li>No more than 5 functions per file</li>
<li>You are allowed to use the C standard library</li>
<li>The prototypes of all your functions should be included in your header file called <code>monty.h</code></li>
<li>Don&rsquo;t forget to push your header file</li>
<li>All your header files should be include guarded</li>
<li>You are expected to do the tasks in the order shown in the project</li>
</ul>

<h3>GitHub</h3>

<p><strong>There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.</strong></p>

<h2>More Info</h2>

<h3>Data structures</h3>

<p>Please use the following data structures for this project. Don&rsquo;t forget to include them in your header file.</p>

<pre><code>/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
</code></pre>

<pre><code>/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
</code></pre>

<h3>Compilation &amp; Output</h3>

<ul>
<li>Your code will be compiled this way:</li>
</ul>

<pre><code>$ gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty
</code></pre>

<ul>
<li>Any output must be printed on <code>stdout</code></li>
<li>Any error message must be printed on <code>stderr</code>

<ul>
<li><a href="/rltoken/9RfVU4j7qVbFgGdMkpX2qA" title="Here is a link to a GitHub repository" target="_blank">Here is a link to a GitHub repository</a> that could help you making sure your errors are printed on <code>stderr</code></li>
</ul></li>
</ul>

<h3>Tests</h3>

<p>We strongly encourage you to work all together on a set of tests</p>

<h3>The Monty language</h3>

<p>Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.</p>

<p><strong>Monty byte code files</strong></p>

<p>Files containing Monty byte codes usually have the <code>.m</code> extension. Most of the industry uses this standard but it is not required by the specification of the language.
There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:</p>

<pre><code>julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
</code></pre>

<p>Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:</p>

<pre><code>julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
</code></pre>

<p><strong>The monty program</strong></p>

<ul>
<li>Usage: <code>monty file</code>

<ul>
<li>where <code>file</code> is the path to the file containing Monty byte code</li>
</ul></li>
<li>If the user does not give any file or more than one argument to your program, print the error message <code>USAGE: monty file</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>If, for any reason, it&rsquo;s not possible to open the file, print the error message <code>Error: Can&#39;t open file &lt;file&gt;</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code>

<ul>
<li>where <code>&lt;file&gt;</code> is the name of the file</li>
</ul></li>
<li>If the file contains an invalid instruction, print the error message <code>L&lt;line_number&gt;: unknown instruction &lt;opcode&gt;</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code>

<ul>
<li>where <line_number> is the line number where the instruction appears.</li>
<li>Line numbers always start at 1</li>
</ul></li>
<li>The monty program runs the bytecodes line by line and stop if either:

<ul>
<li>it executed properly every line of the file</li>
<li>it finds an error in the file</li>
<li>an error occured</li>
</ul></li>
<li>If you can&rsquo;t malloc anymore, print the error message <code>Error: malloc failed</code>, followed by a new line, and exit with status <code>EXIT_FAILURE</code>.</li>
<li>You have to use <code>malloc</code> and <code>free</code> and are not allowed to use any other function from <code>man malloc</code> (realloc, calloc, &hellip;)</li>
</ul>

---

<h2 class="gap">Tasks</h2>
  <span id="user_id" data-id="3430"></span>

#

  <div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b> 0. push, pall </b>
    </h3>
  </div>

  <div class="panel-body">
    <span id="user_id" data-id="3430"></span>

<p><strong>The push opcode</strong></p>

<p>The opcode <code>push</code> pushes an element to the stack.</p>

<ul>
<li>Usage: <code>push &lt;int&gt;</code>

<ul>
<li>where <code>&lt;int&gt;</code> is an integer</li>
</ul></li>
<li>if <code>&lt;int&gt;</code> is not an integer or if there is no argument given to <code>push</code>, print the error message <code>L&lt;line_number&gt;: usage: push integer</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code>

<ul>
<li>where <line_number> is the line number in the file</li>
</ul></li>
<li>You won&rsquo;t have to deal with overflows. Use the <code>atoi</code> function</li>
</ul>

<p><strong>The pall opcode</strong></p>

<p>The opcode <code>pall</code> prints all the values on the stack, starting from the top of the stack.</p>

<ul>
<li>Usage <code>pall</code></li>
<li>Format: see example</li>
<li>If the stack is empty, don&rsquo;t print anything</li>
</ul>

<pre><code>julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$
</code></pre>

  </div>

#

<span id="user_id" data-id="3430"></span>

  <div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>1. pint</b>
    </h3>

  </div>

  <p>Implement the <code>pint</code> opcode.</p>

<p><strong>The pint opcode</strong></p>

<p>The opcode <code>pint</code> prints the value at the top of the stack, followed by a new line.</p>

<ul>
<li>Usage: <code>pint</code></li>
<li>If the stack is empty, print the error message <code>L&lt;line_number&gt;: can&#39;t pint, stack empty</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

<pre><code>julien@ubuntu:~/monty$ cat bytecodes/06.m
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/monty$ ./monty bytecodes/06.m
1
2
3
julien@ubuntu:~/monty$
</code></pre>

#

<div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>2. pop</b>
    </h3>

  </div>

   <div class="panel-body">
    <span id="user_id" data-id="3430"></span>
    <p>Implement the <code>pop</code> opcode.</p>

<p><strong>The pop opcode</strong></p>

<p>The opcode <code>pop</code> removes the top element of the stack.</p>

<ul>
<li>Usage: <code>pop</code></li>
<li>If the stack is empty, print the error message <code>L&lt;line_number&gt;: can&#39;t pop an empty stack</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

<pre><code>julien@ubuntu:~/monty$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/monty$ ./monty bytecodes/07.m 
3
2
1
2
1
1
julien@ubuntu:~/monty$ 
</code></pre>

#

<div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>3. swap</b>
    </h3>
<div class="panel-body">
    <span id="user_id" data-id="3430"></span>
    <p>Implement the <code>swap</code> opcode.</p>

<p><strong>The swap opcode</strong></p>

<p>The opcode <code>swap</code> swaps the top two elements of the stack.</p>

<ul>
<li>Usage: <code>swap</code></li>
<li>If the stack contains less than two elements, print the error message <code>L&lt;line_number&gt;: can&#39;t swap, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

<pre><code>julien@ubuntu:~/monty$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/monty$ ./monty bytecodes/09.m 
3
2
1
2
3
1
julien@ubuntu:~/monty$ 
</code></pre>

#

<div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>4. add</b>
    </h3>
    <p>Implement the <code>add</code> opcode.</p>
<p><strong>The add opcode</strong></p>

<p>The opcode <code>add</code> adds the top two elements of the stack.</p>

<ul>
<li>Usage: <code>add</code></li>
<li>If the stack contains less than two elements, print the error message <code>L&lt;line_number&gt;: can&#39;t add, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

<ul>
<li>The top element of the stack contains the result</li>
<li>The stack is one element shorter</li>
</ul></li>
</ul>

<pre><code>julien@ubuntu:~/monty$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

julien@ubuntu:~/monty$ ./monty bytecodes/12.m 
3
2
1
5
1
julien@ubuntu:~/monty$
</code></pre>

#

<div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>5. nop</b>
    </h3>
<p>Implement the <code>nop</code> opcode.</p>

<p><strong>The nop opcode</strong></p>

<p>The opcode <code>nop</code> doesn&rsquo;t do anything.</p>

<ul>
<li>Usage: <code>nop</code></li>
</ul>

  </div>

#

<div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>6. sub</b>
    </h3>
<p>Implement the <code>sub</code> opcode.</p>

<p><strong>The sub opcode</strong></p>

<p>The opcode <code>sub</code> subtracts the top element of the stack from the second top element of the stack.</p>

<ul>
<li>Usage: <code>sub</code></li>
<li>If the stack contains less than two elements, print the error message <code>L&lt;line_number&gt;: can&#39;t sub, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

<ul>
<li>The top element of the stack contains the result</li>
<li>The stack is one element shorter</li>
</ul></li>
</ul>

<pre><code>julien@ubuntu:~/monty$ cat bytecodes/19.m 
push 1
push 2
push 10
push 3
sub
pall
julien@ubuntu:~/monty$ ./monty bytecodes/19.m 
7
2
1
julien@ubuntu:~/monty$
</code></pre>

  </div>

#

<div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>7. div</b>
    </h3>
	<p>Implement the <code>div</code> opcode.</p>

<p><strong>The div opcode</strong></p>

<p>The opcode <code>div</code> divides the second top element of the stack by the top element of the stack.</p>

<ul>
<li>Usage: <code>div</code></li>
<li>If the stack contains less than two elements, print the error message <code>L&lt;line_number&gt;: can&#39;t div, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

<ul>
<li>The top element of the stack contains the result</li>
<li>The stack is one element shorter</li>
</ul></li>
<li>If the top element of the stack is <code>0</code>, print the error message <code>L&lt;line_number&gt;: division by zero</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

  </div>

#

<div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>8. mul</b>
    </h3>
<p>Implement the <code>mul</code> opcode.</p>

<p><strong>The mul opcode</strong></p>

<p>The opcode <code>mul</code> multiplies the second top element of the stack with the top element of the stack.</p>

<ul>
<li>Usage: <code>mul</code></li>
<li>If the stack contains less than two elements, print the error message <code>L&lt;line_number&gt;: can&#39;t mul, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

<ul>
<li>The top element of the stack contains the result</li>
<li>The stack is one element shorter</li>
</ul></li>
</ul>

  </div>

#

<div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>9. mod</b>
    </h3>
	<p>Implement the <code>mod</code> opcode.</p>

<p><strong>The mod opcode</strong></p>

<p>The opcode <code>mod</code> computes the rest of the division of the second top element of the stack by the top element of the stack.</p>

<ul>
<li>Usage: <code>mod</code></li>
<li>If the stack contains less than two elements, print the error message <code>L&lt;line_number&gt;: can&#39;t mod, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

<ul>
<li>The top element of the stack contains the result</li>
<li>The stack is one element shorter</li>
</ul></li>
<li>If the top element of the stack is <code>0</code>, print the error message <code>L&lt;line_number&gt;: division by zero</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

  </div>

#

<div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>10. comments</b>
    </h3>
	<p>Every good language comes with the capability of commenting. When the first non-space character of a line is <code>#</code>, treat this line as a comment (don&rsquo;t do anything).</p>

  </div>

#

 <div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>11. pchar</b>
    </h3>
	<p>Implement the <code>pchar</code> opcode.</p>

<p><strong>The pchar opcode</strong></p>

<p>The opcode <code>pchar</code> prints the char at the top of the stack, followed by a new line.</p>

<ul>
<li>Usage: <code>pchar</code></li>
<li>The integer stored at the top of the stack is treated as the ascii value of the character to be printed</li>
<li>If the value is not in the ascii table (man ascii) print the error message <code>L&lt;line_number&gt;: can&#39;t pchar, value out of range</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>If the stack is empty, print the error message <code>L&lt;line_number&gt;: can&#39;t pchar, stack empty</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

<pre><code>julien@ubuntu:~/monty$ cat bytecodes/28.m 
push 72
pchar
julien@ubuntu:~/monty$ ./monty bytecodes/28.m 
H
julien@ubuntu:~/monty$
</code></pre>

  </div>

#

 <div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>12. pstr</b>
    </h3>
	<p>Implement the <code>pstr</code> opcode.</p>

<p><strong>The pstr opcode</strong></p>

<p>The opcode <code>pstr</code> prints the string starting at the top of the stack, followed by a new line.</p>

<ul>
<li>Usage: <code>pstr</code></li>
<li>The integer stored in each element of the stack is treated as the ascii value of the character to be printed</li>
<li>The string stops when either:

<ul>
<li>the stack is over</li>
<li>the value of the element is 0</li>
<li>the value of the element is not in the ascii table</li>
</ul></li>
<li>If the stack is empty, print only a new line</li>
</ul>

<pre><code>julien@ubuntu:~/monty$ cat bytecodes/31.m 
push 1
push 2
push 3
push 4
push 0
push 110
push 0
push 108
push 111
push 111
push 104
push 99
push 83
pstr
julien@ubuntu:~/monty$ ./monty bytecodes/31.m 
School
julien@ubuntu:~/monty$ 
</code></pre>

  </div>

#

<div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>13. rotl</b>
    </h3>
	<p>Implement the <code>rotl</code> opcode.</p>

<p><strong>The rotl opcode</strong></p>

<p>The opcode <code>rotl</code> rotates the stack to the top.</p>

<ul>
<li>Usage: <code>rotl</code></li>
<li>The top element of the stack becomes the last one, and the second top element of the stack becomes the first one</li>
<li><code>rotl</code> never fails</li>
</ul>

<pre><code>julien@ubuntu:~/monty$ cat bytecodes/35.m 
push 1
push 2
push 3
push 4
push 5
push 6
push 7
push 8
push 9
push 0
pall
rotl
pall
julien@ubuntu:~/monty$ ./monty bytecodes/35.m 
0
9
8
7
6
5
4
3
2
1
9
8
7
6
5
4
3
2
1
0
julien@ubuntu:~/monty$ 
</code></pre>

  </div>

#

<div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>14. rotr</b>
    </h3>
	<p>Implement the <code>rotr</code> opcode.</p>

<p><strong>The rotr opcode</strong></p>

<p>The opcode <code>rotr</code> rotates the stack to the bottom.</p>

<ul>
<li>Usage: <code>rotr</code></li>
<li>The last element of the stack becomes the top element of the stack</li>
<li><code>rotr</code> never fails</li>
</ul>

  </div>

#

<div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>15. stack, queue</b>
    </h3>
<p>Implement the <code>stack</code> and <code>queue</code> opcodes.</p>

<p><strong>The stack opcode</strong></p>

<p>The opcode <code>stack</code> sets the format of the data to a stack (LIFO). This is the default behavior of the program.</p>

<ul>
<li>Usage: <code>stack</code></li>
</ul>

<p><strong>The queue opcode</strong></p>

<p>The opcode <code>queue</code> sets the format of the data to a queue (FIFO).</p>

<ul>
<li>Usage: <code>queue</code></li>
</ul>

<p>When switching mode:</p>

<ul>
<li>The top of the stack becomes the front of the queue</li>
<li>The front of the queue becomes the top of the stack</li>
</ul>

<pre><code>julien@ubuntu:~/monty$ cat bytecodes/47.m
queue
push 1
push 2
push 3
pall
stack
push 4
push 5
push 6
pall
add
pall
queue
push 11111
add
pall
julien@ubuntu:~/monty$ ./monty bytecodes/47.m
1
2
3
6
5
4
1
2
3
11
4
1
2
3
15
1
2
3
11111
julien@ubuntu:~/monty$ 
</code></pre>

  </div>

#

<div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>16. Brainf*ck</b>
    </h3>
<p>Write a Brainf*ck script that prints <code>School</code>, followed by a new line.</p>

<ul>
<li>All your Brainf*ck files should be stored inside the <code>bf</code> sub directory</li>
<li>You can install the <code>bf</code> interpreter to test your code: <code>sudo apt-get install bf</code></li>
<li>Read: <a href="/rltoken/3YPS6XwLxjZp4qnguP1HYg" title="Brainf*ck" target="_blank">Brainf*ck</a> </li>
</ul>

<pre><code>julien@ubuntu:~/monty/bf$ bf 1000-school.bf 
School
julien@ubuntu:~/monty/bf$ 
</code></pre>

  </div>

#

<div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>17. Add two digits</b>
    </h3>
	<p>Add two digits given by the user.</p>

<ul>
<li>Read the two digits from stdin, add them, and print the result</li>
<li>The total of the two digits with be one digit-long (&lt;10)</li>
</ul>

<pre><code>julien@ubuntu:~/monty/bf$ bf ./1001-add.bf
81
9julien@ubuntu:~/monty/bf$
</code></pre>

  </div>

#

<div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>18. Multiplication</b>
    </h3>
	<p>Multiply two digits given by the user.</p>

<ul>
<li>Read the two digits from stdin, multiply them, and print the result</li>
<li>The result of the multiplication will be one digit-long (&lt;10)</li>
</ul>

<pre><code>julien@ubuntu:~/monty/bf$ bf 1002-mul.bf
24
8julien@ubuntu:~/monty/bf$
</code></pre>

  </div>

#

<div class="panel-heading panel-heading-actions">
    <h3 class="panel-title">
      <b>19. Multiplication level up</b>
    </h3>
	<p>Multiply two digits given by the user.<br />
<br />
<img src="https://holbertonintranet.s3.amazonaws.com/uploads/medias/2021/5/262086c8a6e417b9b15a5d4f46d339ebbabce218.jpg?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOU5BHMTQX4%2F20220111%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20220111T144035Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=657b8aeb8712fa8dff7e3a6c8037a8c4ca6406e9b265b5ce15c05e2ad4464253" alt="" style="" />
<br /></p>

<ul>
<li>Read the two digits from stdin, multiply them, and print the result, followed by a new line</li>
</ul>

<pre><code>julien@ubuntu:~/monty/bf$ bf 1003-mul.bf 
77
49
julien@ubuntu:~/monty/bf$ 
</code></pre>

  </div>
