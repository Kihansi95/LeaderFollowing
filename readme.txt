TP2 : IA
Vanleene Sacha
Faget Homas
Nguyen DUc Hau



Implémentation : 
Nous avons crée trois classes : 
	-Follower
	-Leader
	-Vehicle_keyboard


Follower : 
Nous avons réduit le poids des followers de manière à réduire leurs inertie. De plus ces agent disposent de deux comportements. Un comportement de poursuite avec offset lié à un autre agent et un comportement de séparation de manière à répondre au cahier des charges du projet.
Leader:
Ce type d'agent se distingue à l'écran par sa taille, plus importante que celle des followers. De plus cet agent dispose d'un seul comportement : le Wander. Nous avons également modifier ses paramètres pour modifier son inertie et ainsi lui donner des trajectoire plus rectilignes : augmenter son rayon de courbure. 
Vehicle_Keyboard : 
Agent qui visuellement est semblable au leader. Toutefois il ne dispose d'aucun steering behavior. Tout est géré au clavier, appuyer sur w , s, a ou bien d va générer  une force en cohérence avec la touche choisie. 

Guide d'utilisation : 
Les agents se suivent les un les autres en respectant leurs place dans la liste de l'ensemble des vehicules crées. Ce qui implique que nous ajoutons toujours le leader en première de cette file " m_vehicles".
Pour switcher du leader au leader_humain il suffit de commenter ou decommenter la création de  dernier en gardant toujours l'autre commenté.


Question 3 : Etant donné que nos agents suiveurs sont pré programmés pour suivre une seul et même personne, l'ajout d'un autre leader n'a que peu d'influence. Effectivement seul le comportement de séparation entre les agents aura un effet, mais le poursuite offset étant lié à un autre agent cela n'influe pas ce comportement. Toutefois cela aurait un impact si on lie un agent poursuiveur quelconque à un second leader, dans ce cas on pourrait se retrouver avec deux groupes, pour parler de manière plus visuel : deux files indiennes ...


Question 4 : Le fait d'avoir un agent humain facilite les agents à se ranger en file indienne. Effectivement le comportement aléatoire à tendance à sortir de la fenêtre et à revenir par le bord opposé ce qui, souvent, désoriente les agents poursuiveurs puisque non robuste à ce genre d'effet de bord.
