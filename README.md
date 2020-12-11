# Movie Recommendation Generator
 
### Authors:
 * [Gary Ou](https://github.com/GaryOu101)
 * [Matthew O'Grady](https://github.com/mattrogrady)
 * [Jakin Chan](https://github.com/JakinChan200)

## Project Description
#### Goal

* To recommend movies in a neat format based on user input

#### Importance and Interest

* With hundreds of movies being released per year all over the world in different languages, it becomes increasingly difficult to find one that fits one's tastes. At the same time, one may be constrained by their own movie prefereces, unaware of the untapped potential of the beyond. Most recommended movies are already top movies, with little regard to the rest of the film industry. With this application, the goal is not to only recommend movies, but to introduce the user to new genres and movies that while related to what the user already likes, is not just a list of top movies.

#### Language and Tools

 * C++

#### Input/Output

&nbsp;&nbsp;&nbsp;&nbsp;Input: Desired genres, Runtime, Rating, and Release Year of Movies

&nbsp;&nbsp;&nbsp;&nbsp;Output: Movie recommendations based on input

#### Design Patterns
1. Composite Pattern (Jakin Chan): To store movies under specific catagories
   ![Composite Design Pattern (1)](https://user-images.githubusercontent.com/42459094/101896527-00b8ae80-3b5e-11eb-9e77-b376b93eec86.jpg)

2. Visitor Pattern (Matthew O'Grady): Gets the movie objects from their respective categories
   ![Composite Design Pattern (4)](https://user-images.githubusercontent.com/42459094/101943632-4a29ed80-3ba0-11eb-9a3b-dec3e42bec1e.jpg)
   
3. Decorator Pattern (Gary Ou): To add extra information about the outputted movies
   ![Composite Design Pattern (3)](https://user-images.githubusercontent.com/42459094/101896629-1ded7d00-3b5e-11eb-8f08-bcb1d85616a3.jpg)

 ## Screenshots
 ![Example Screenshot 1](https://user-images.githubusercontent.com/42446873/101939024-3929ae00-3b99-11eb-9a84-88ffbf1c873b.png)
 ![Example Screenshot 2](https://user-images.githubusercontent.com/42446873/101939078-52caf580-3b99-11eb-911f-54dfc795c4fb.png)
 ![Example Screenshot 3](https://user-images.githubusercontent.com/42446873/101939092-5a8a9a00-3b99-11eb-8876-666cecbb0dd2.png)
 ## Installation/Usage
 In order to install this program, open your local terminal and clone this repository first. Afterwards, one must run the command "cmake3 ." to create the makefile followed by "make" to compile the code. At this point, the code is ready to be executed so the user must run the command "./main" in order to run the program. If the user wants to make changes in the code, they must re-run the "make" command in order to re-compile the code, before running "./main". 
 ## Testing
This project was tested using googletest. There is a file called unit_test.cpp which runs all the tests, while each pattern was tested in its own file (decorator_test.hpp, movieComp_test.hpp, visitor_test.hpp). Therefore, unit_test.cpp would include each of these tests and simply instruct googletest to run all of them.
 
