#ifndef PPM_H
#define PPM_H

struct ppm_pixel {
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

static inline void ppm_setpixel(struct ppm_pixel *px, unsigned char r,
                                unsigned char g, unsigned char b) {
  px->r = r;
  px->g = g;
  px->b = b;
}

struct ppm_image {
  unsigned int width;
  unsigned int height;
  struct ppm_pixel *px;
};

int ppm_image_init(struct ppm_image *im, int w, int h);
int ppm_image_release(struct ppm_image *im);

static inline void ppm_image_setpixel(struct ppm_image *im, int x, int y,
                                      unsigned char r, unsigned char g,
                                      unsigned char b) {
  struct ppm_pixel *px = im->px + im->width * y + x;
  ppm_setpixel(px, r, g, b);
}

int ppm_image_dump(struct ppm_image *im, char *path);

/*
Le fichier `ppm.h` fournit les structures et fonctions pour manipuler des images au format PPM :

- struct ppm_pixel : Représente un pixel avec des composantes rouge (r), verte (g) et bleue (b).

- struct ppm_image: Contient les dimensions de l'image (largeur et hauteur) et un tableau de pixels.

Fonctions principales :

- ppm_image_init : Initialise une image avec des dimensions spécifiées.

- ppm_image_release : Libère la mémoire allouée à une image.

- ppm_image_dump : Enregistre l'image dans un fichier au format PPM.

Fonctions d'aide :

- ppm_setpixel: Définit la couleur d'un pixel.

- ppm_image_setpixel : Définit la couleur d'un pixel dans l'image à des coordonnées spécifiques.
*/

#endif /* PPM_H */

