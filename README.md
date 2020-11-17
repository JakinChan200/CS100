# Movie Recommendation Generator
 
### Authors:
 * [Gary Ou](https://github.com/GaryOu101)
 * [Matthew O'Grady](https://github.com/mattrogrady)
 * [Jakin Chan](https://github.com/JakinChan200)

## Project Description
#### Goal

* Utilize TMDb's API to recommend movies based on user input and put recommended movies onto files

#### Importance and Interest

* With hundreds of movies being released per year all over the world in different languages, it becomes increasingly difficult to find one that fits one's tastes. At the same time, one may be constrained by their own movie prefereces, unaware of the untapped potential of the beyond. Most recommended movies are already top movies, with little regard to the rest of the film industry. With this application, the goal is not to only recommend movies, but to introduce the user to new genres and movies that while related to what the user already likes, is not just a list of top movies.

#### Language and Tools

 * C++
 * [TMDb API](https://www.themoviedb.org/documentation/api)

#### Input/Output

&nbsp;&nbsp;&nbsp;&nbsp;Input: Desired genres, actors, and/or review criteria

&nbsp;&nbsp;&nbsp;&nbsp;Output: Movie recommendations based on input

#### Design Patterns
1. Abstract Factory Pattern (Jakin Chan): I chose this pattern because we needed a way to store the movie information. So a solution was to create movie objects. This design pattern is utilized to create the needed  objects to store the movie information.
 
2. Visitor Pattern (Matthew O'Grady): The visitor pattern provides a way to separate an algorithm from the object structure that it is operating on. Due to its nature, this pattern provides the ideal way to interact with the movie objects that are pulled from the TMDb API. This way, the preferences that a user enters for genre, actors, and review criteria can easily be compared against the movie data from TMDb without having to modify the source. Because this pattern provides an easier way to run algorithms against TMDb movie data, we can easily form the list of movies that we recommend. 

3. Decorator Pattern (Gary Ou):The Decorator Pattern is intended to add extra functionality (decorate) to objects. In this project, we will use the decorator pattern to format and output relevant information from the movie objects. The output generated will list the genre, important actors, and ratings of the recommended movie.
   ![movieDecorator](https://user-images.githubusercontent.com/42448439/99351254-0cfa6600-2855-11eb-9692-07575ffba4f6.PNG)
   Description of Class Diagram: After computing the recommended movie, a movieInfo object is created to formulate an output message. We output relevant information about the movie through decorator objects, which will wrap/decorate (adding functionalities) to the movieInfo object. The decorator classes addGenre, addMovieDesc, addMovieTitle and addActors are the classes that will wrap over the movieInfo object and output their respective information.
 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
