---
title: "Utiliser un CNAME pour Github Page"
category: "tips"
date: "2018-06-19"
slug: "cname-github-page"
cover: "https://picsum.photos/1152/500/?image=811"
author: "dck"
tags:
    - tips
    - github
---

J'ai récemment passé mon site personnel sur Github afin de profiter de [Github Page](https://pages.github.com/). Ca m'évite à devoir gérer de l'infratstructure pour un site "bateau".

Par défaut avec Github Page d'activé dans votre repo, vous avez un nom de domaine :
`<pseudoGithub>.github.io/nomdurepo`.

Ayant déjà un nom de domaine, j'ai souhaité le ré-utiliser, j'ai du pour cela ajouter un **CNAME** dans la zone DNS de mon provider (ici OVH) :

```
www IN CNAME dckt.github.io.
```

<br />

## Disparition du nom de domaine

J'utilise Gatsby et le module npm [gh-pages](https://www.npmjs.com/package/gh-pages) pour faire mes déploiements une fois le site construit. J'ai pu constater [un bug](https://github.com/tschaub/gh-pages/issues/213) avec la librairie _gh-pages_ qui efface notre nom de domaine après chaque déploiement.

La solution à ce problème est de créer un fichier nommé `CNAME` à la racine du projet contenant votre nom de domaine. Dans mon cas :

```
thomasdeconinck.fr
```

**Note :**
Dans mon cas avec Gatsby qui build tout dans le dossier `public`, j'ai ajouté une commande qui fait un `cp` de mon fichier dans ce répertoire.
