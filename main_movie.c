#include <stdio.h> 
#include "Rating.h" 
#include "Movie.h" 

int main(void) 
{ 
	Movie *movies = read100Movies();
	Movie *m;
	Rating *r;
	
	int numMovies = 0; 
	int numRatings = 0;
	int maximum = 0;
	double avgRating = 0;
	int avgMax = 0;
	int maxTime = 0; 
	int minTime = 0;
	int maximum1 = 0;
	int i = 0;
	int avgMax1=0;
	int latestRating = 0;
	int earliestRating = 10000000;
	
	//______________________________________________________// 

	for (m = movies; m != NULL; m = m->next){ 
	numMovies++;} 
	
	printf("Number of movies = %d\n", numMovies); 
	//______________________________________________________// 
	
	for (m = movies; m != NULL; m = m->next) 
	{ 
		numRatings+= m-> numRatings; 
	} 
	printf("Number of ratings = %d\n", numRatings); 
	//______________________________________________________// 
	
	
	for  (m = movies; m != NULL; m = m -> next) 
	{			
		if (m->numRatings > maximum) 
		{ 
			maximum = m->numRatings;
			maximum1 = m->id;
		}	 	
	} 
	
	printf("The maximum number of ratings is: %d\n", maximum); 
	printf("The movie with most ratings is: %s\n", title(maximum1) ); 
	
	//______________________________________________________// 
	
	for (m = movies; m !=NULL; m = m -> next) 
	{		
		if (m->avgRating > avgMax) 
		{ 
			avgMax = m->avgRating; 
			avgMax1 = m->id;
		} 
	}
	printf("The maximum average rating is: %d\n", avgMax);
	printf("The movie with highest average rating is: %s\n", title(avgMax1));
	 
	//______________________________________________________// 
	
	for (r = movies->ratings; r!=NULL; r = r ->next) 
	{ 	
		if (r->date < earliestRating) 
		{ 
			earliestRating = r->date; 
		} 
		
		if (r->date > latestRating) 
		{ 
			latestRating = r->date;
		}
		
	
	}
	printf("The date of the earliest rating is: %s\n", getDate(earliestRating));	
	printf("The date of the latest rating is: %s\n", getDate(latestRating));
	
	freeMovies(movies);
	freeRatings(r);
return 0;
}
