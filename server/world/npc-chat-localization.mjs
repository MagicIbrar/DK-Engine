// ENGINE-CHOSEN authored language packs. These are not official Global language
// coverage or machine translation. Unknown factual prose stays in English.
export const NPC_CHAT_LANGUAGES=Object.freeze(['en','es','pt','de','fr']);
const locales=['es','pt','de','fr'];
const whole=[
 ['I am coming with you.','Voy contigo.','Vou com você.','Ich komme mit dir.','Je viens avec toi.'],
 ['Give me a sec, on my way.','Dame un segundo, ya voy.','Só um segundo, já vou.','Einen Moment, ich komme.','Une seconde, j’arrive.'],
 ['Got you, I will follow.','Entendido, te seguiré.','Entendido, vou seguir.','Verstanden, ich folge dir.','Compris, je te suis.'],
 ['I will stay here.','Me quedaré aquí.','Vou ficar aqui.','Ich bleibe hier.','Je reste ici.'],
 ['Taking a breather here.','Descansando aquí un momento.','Descansando aqui um pouco.','Ich mache hier kurz Pause.','Je souffle un peu ici.'],
 ['Waiting, tell me when to move.','Espero, avísame cuándo moverme.','Esperando, avise quando sair.','Ich warte, sag mir, wann es weitergeht.','J’attends, dis-moi quand repartir.'],
 ['Alright, I will stay with you.','Vale, me quedaré contigo.','Certo, vou ficar com você.','Okay, ich bleibe bei dir.','D’accord, je reste avec toi.'],
 ['I can come along. Keep a steady pace.','Puedo acompañarte. Mantén un ritmo constante.','Posso acompanhar você. Mantenha um ritmo constante.','Ich kann mitkommen. Halte ein gleichmäßiges Tempo.','Je peux venir. Garde un rythme régulier.'],
 ['Sure, lead and I will keep up.','Claro, guía y te seguiré.','Claro, lidere e vou acompanhar.','Klar, geh voran und ich halte mit.','Bien sûr, mène et je suis.'],
 ['I will follow your route.','Seguiré tu ruta.','Vou seguir sua rota.','Ich folge deinem Weg.','Je suivrai ton chemin.'],
 ['Okay, let us move together.','Vale, vamos juntos.','Certo, vamos juntos.','Okay, gehen wir zusammen.','D’accord, avançons ensemble.'],
 ['I will stay close to the party.','Me quedaré cerca del grupo.','Vou ficar perto do grupo.','Ich bleibe in der Nähe der Gruppe.','Je reste près du groupe.'],
 ['On my way. Wait if the route gets blocked.','Ya voy. Espera si el camino está bloqueado.','Já vou. Espere se o caminho ficar bloqueado.','Ich komme. Warte, wenn der Weg blockiert ist.','J’arrive. Attends si le chemin est bloqué.'],
 ['I will come with you for this bit.','Te acompañaré este tramo.','Vou acompanhar você neste trecho.','Ich komme dieses Stück mit dir.','Je t’accompagne pour ce passage.'],
 ['Alright. Which entrance are we heading for?','Vale. ¿A qué entrada vamos?','Certo. Para qual entrada vamos?','Okay. Zu welchem Eingang gehen wir?','D’accord. Vers quelle entrée allons-nous ?'],
 ['I am coming. Give me room to get through.','Voy. Déjame espacio para pasar.','Estou indo. Deixe espaço para eu passar.','Ich komme. Lass mir Platz zum Durchgehen.','J’arrive. Laisse-moi de la place pour passer.'],
 ['Sure. Let us avoid splitting the pull.','Claro. Evitemos dividir el grupo de enemigos.','Claro. Vamos evitar separar os monstros atraídos.','Klar. Teilen wir die angelockten Gegner nicht auf.','Bien sûr. Évitons de séparer les ennemis attirés.'],
 ['I will stick nearby. You lead.','Me quedaré cerca. Tú guías.','Vou ficar por perto. Você lidera.','Ich bleibe in der Nähe. Du gehst voran.','Je reste près de toi. Tu mènes.'],
 ['Okay, I will wait at this spot.','Vale, esperaré en este sitio.','Certo, vou esperar neste lugar.','Okay, ich warte hier an dieser Stelle.','D’accord, j’attends à cet endroit.'],
 ['Holding here. Let me know when you are ready.','Me quedo aquí. Avísame cuando estés listo.','Fico aqui. Avise quando estiver pronto.','Ich warte hier. Sag Bescheid, wenn du bereit bist.','Je reste ici. Préviens-moi quand tu es prêt.'],
 ['I can wait while you sort that out.','Puedo esperar mientras lo solucionas.','Posso esperar enquanto você resolve isso.','Ich kann warten, während du das klärst.','Je peux attendre pendant que tu règles ça.'],
 ['Alright, taking a short pause.','Vale, hago una pequeña pausa.','Certo, fazendo uma pausa rápida.','Okay, ich mache kurz Pause.','D’accord, je fais une courte pause.'],
 ['I will stop moving for now.','Dejaré de moverme por ahora.','Vou parar de me mover por enquanto.','Ich bleibe vorerst stehen.','Je m’arrête pour le moment.'],
 ['Waiting here until the party is ready.','Espero aquí hasta que el grupo esté listo.','Esperando aqui até o grupo estar pronto.','Ich warte hier, bis die Gruppe bereit ist.','J’attends ici que le groupe soit prêt.'],
 ['Okay, we can regroup here.','Vale, podemos reagruparnos aquí.','Certo, podemos reagrupar aqui.','Okay, wir können uns hier sammeln.','D’accord, on peut se regrouper ici.'],
 ['I will stay put for a bit.','Me quedaré quieto un rato.','Vou ficar parado um pouco.','Ich bleibe kurz hier stehen.','Je reste sur place un moment.'],
 ['Stopping. Finish what you were doing.','Me detengo. Termina lo que estabas haciendo.','Parando. Termine o que estava fazendo.','Ich halte an. Mach erst fertig, was du gerade tust.','Je m’arrête. Termine ce que tu faisais.'],
 ['Alright. No rush from me.','Vale. No tengo prisa.','Certo. Sem pressa da minha parte.','Okay. Von mir aus keine Eile.','D’accord. Rien ne presse pour moi.'],
 ['I will hold this spot while you catch up.','Esperaré aquí mientras llegas.','Vou esperar aqui enquanto você alcança.','Ich warte hier, bis du aufgeschlossen hast.','Je reste ici pendant que tu nous rejoins.'],
 ['Okay, tell me when to follow again.','Vale, dime cuándo seguirte otra vez.','Certo, diga quando seguir novamente.','Okay, sag mir, wann ich wieder folgen soll.','D’accord, dis-moi quand te suivre à nouveau.'],
 ['Want to party up?','¿Quieres formar grupo?','Quer formar grupo?','Willst du eine Gruppe bilden?','Tu veux former un groupe ?'],
 ['We can team up.','Podemos jugar en equipo.','Podemos jogar em equipe.','Wir können zusammen spielen.','On peut faire équipe.'],
 ['Room in your party?','¿Hay sitio en tu grupo?','Tem espaço no seu grupo?','Noch Platz in deiner Gruppe?','Il reste une place dans ton groupe ?'],
 ['Hey, what are you up to?','Hola, ¿qué estás haciendo?','Olá, o que você está fazendo?','Hallo, was machst du gerade?','Salut, que fais-tu ?'],
 ['Hi, need a party?','Hola, ¿necesitas un grupo?','Olá, precisa de um grupo?','Hallo, brauchst du eine Gruppe?','Salut, tu cherches un groupe ?'],
 ['Hey, how is the grind?','Hola, ¿cómo va la caza?','Olá, como vai a caçada?','Hallo, wie läuft das Kämpfen?','Salut, comment se passe la chasse ?'],
 ['Take care.','Cuídate.','Se cuida.','Pass auf dich auf.','Prends soin de toi.'],
 ['You are welcome.','De nada.','De nada.','Gern geschehen.','Avec plaisir.'],
 ['No worries.','No te preocupes.','Sem problema.','Kein Problem.','Pas de souci.'],
 ['I am an automated player, not a person.','Soy un jugador automatizado, no una persona.','Sou um jogador automatizado, não uma pessoa.','Ich bin ein automatisierter Spieler, kein Mensch.','Je suis un joueur automatisé, pas une personne.'],
 ['K, following.','Vale, te sigo.','Certo, vou seguir.','Okay, ich folge dir.','D’accord, je te suis.'],
 ['Lead the way.','Guía el camino.','Mostre o caminho.','Geh voran.','Montre le chemin.'],
 ['K, waiting here.','Vale, espero aquí.','Certo, espero aqui.','Okay, ich warte hier.','D’accord, j’attends ici.'],
 ['Stopping here.','Me detengo aquí.','Vou parar aqui.','Ich bleibe hier stehen.','Je m’arrête ici.'],
 ['I can come along.','Puedo acompañarte.','Posso acompanhar você.','Ich kann mitkommen.','Je peux t’accompagner.'],
 ['I can wait here.','Puedo esperar aquí.','Posso esperar aqui.','Ich kann hier warten.','Je peux attendre ici.'],
 ['I can get back to my own route.','Puedo volver a mi ruta.','Posso voltar à minha rota.','Ich kann zu meiner eigenen Route zurückkehren.','Je peux reprendre mon itinéraire.'],
 ['I can help with a careful pull.','Puedo ayudar a atraer enemigos con cuidado.','Posso ajudar a atrair inimigos com cuidado.','Ich kann beim vorsichtigen Anlocken helfen.','Je peux aider à attirer prudemment un ennemi.'],
 ['I am open to a party.','Me interesa formar un grupo.','Tenho interesse em um grupo.','Ich bin für eine Gruppe offen.','Je suis partant pour un groupe.'],
 ['I can get ready with you.','Puedo prepararme contigo.','Posso me preparar com você.','Ich kann mich mit dir vorbereiten.','Je peux me préparer avec toi.'],
 ['I am up for a duel if the area allows it.','Acepto un duelo si la zona lo permite.','Aceito um duelo se a área permitir.','Ich bin für ein Duell bereit, wenn die Gegend es erlaubt.','Je suis partant pour un duel si la zone le permet.'],
 ['Got room for one?','¿Hay sitio para uno más?','Tem espaço para mais um?','Ist noch ein Platz frei?','Il reste une place ?'],
 ['I can send you a party invite.','Puedo enviarte una invitación al grupo.','Posso enviar um convite de grupo.','Ich kann dir eine Gruppeneinladung senden.','Je peux t’envoyer une invitation de groupe.'],
 ['We can team up.','Podemos formar un equipo.','Podemos formar uma equipe.','Wir können zusammen spielen.','Nous pouvons faire équipe.'],
 ['I will pull one back.','Traeré un enemigo hacia aquí.','Vou trazer um inimigo para cá.','Ich locke einen Gegner hierher.','Je vais attirer un ennemi ici.'],
 ['We need to get the party together first.','Primero debemos reunir al grupo.','Precisamos reunir o grupo primeiro.','Wir müssen zuerst die Gruppe versammeln.','Il faut d’abord rassembler le groupe.'],
 ['Meet the party at the entrance.','Reúnete con el grupo en la entrada.','Encontre o grupo na entrada.','Triff die Gruppe am Eingang.','Retrouve le groupe à l’entrée.'],
 ['I will stick with the leader inside.','Seguiré al líder dentro.','Vou acompanhar o líder lá dentro.','Drinnen bleibe ich beim Anführer.','À l’intérieur, je reste avec le chef.'],
 ['Whisper me if you need a hand.','Envíame un mensaje privado si necesitas ayuda.','Mande uma mensagem privada se precisar de ajuda.','Flüstere mir, wenn du Hilfe brauchst.','Envoie-moi un message privé si tu as besoin d’aide.'],
 ['You can ask me to wait or follow.','Puedes pedirme que espere o te siga.','Pode pedir para eu esperar ou seguir.','Du kannst mich bitten zu warten oder zu folgen.','Tu peux me demander d’attendre ou de te suivre.'],
 ['Ask about my gear, level or current run.','Pregunta por mi equipo, nivel o actividad actual.','Pergunte sobre meu equipamento, nível ou atividade atual.','Frag nach meiner Ausrüstung, meinem Level oder meiner aktuellen Aufgabe.','Demande-moi mon équipement, mon niveau ou mon activité actuelle.'],
 ['I cannot take that request right now.','No puedo aceptar esa petición ahora.','Não posso aceitar esse pedido agora.','Ich kann diese Bitte gerade nicht annehmen.','Je ne peux pas accepter cette demande maintenant.'],
 ['I am staying with someone else right now. Please check with them.','Estoy acompañando a otra persona. Consúltalo con ella.','Estou acompanhando outra pessoa. Fale com ela primeiro.','Ich bleibe gerade bei jemand anderem. Bitte sprich mit dieser Person.','J’accompagne déjà quelqu’un. Demande-lui d’abord.'],
 ['I am staying with my current party. Please check with them.','Me quedo con mi grupo actual. Consúltalo con ellos.','Vou ficar com meu grupo atual. Fale com eles primeiro.','Ich bleibe bei meiner aktuellen Gruppe. Bitte sprich mit ihnen.','Je reste avec mon groupe actuel. Demande-leur d’abord.'],
 ['I am already with another party.','Ya estoy en otro grupo.','Já estou em outro grupo.','Ich bin schon in einer anderen Gruppe.','Je suis déjà dans un autre groupe.'],
 ['Let me finish this skill first.','Déjame terminar esta habilidad primero.','Deixe-me terminar esta habilidade primeiro.','Lass mich zuerst diese Fertigkeit beenden.','Laisse-moi d’abord terminer cette compétence.'],
 ['I am finishing a trade right now.','Estoy terminando un intercambio.','Estou terminando uma troca.','Ich schließe gerade einen Handel ab.','Je termine un échange.'],
 ['I am keeping my shop open for now.','Por ahora mantengo mi tienda abierta.','Vou manter minha loja aberta por enquanto.','Ich lasse meinen Laden vorerst geöffnet.','Je garde ma boutique ouverte pour le moment.'],
 ['I need to deal with this fight first.','Primero debo terminar este combate.','Preciso terminar esta luta primeiro.','Ich muss zuerst diesen Kampf beenden.','Je dois d’abord terminer ce combat.'],
 ['I need to recover some health first.','Primero debo recuperar algo de vida.','Preciso recuperar um pouco de vida primeiro.','Ich muss zuerst etwas Gesundheit regenerieren.','Je dois d’abord récupérer un peu de vie.'],
 ['I need to recover some mana before preparing.','Debo recuperar algo de maná antes de prepararme.','Preciso recuperar mana antes de me preparar.','Ich muss vor der Vorbereitung etwas Mana regenerieren.','Je dois récupérer du mana avant de me préparer.'],
 ['Thanks, but I want to do this on my own for now.','Gracias, pero por ahora quiero hacerlo por mi cuenta.','Obrigado, mas quero fazer isso sozinho por enquanto.','Danke, aber ich möchte das vorerst allein machen.','Merci, mais je préfère le faire seul pour le moment.'],
 ['I am finishing this quest first. Ask me after this step.','Primero termino esta misión. Pregúntame después de este paso.','Vou terminar esta missão primeiro. Pergunte depois desta etapa.','Ich beende zuerst diese Quest. Frag mich nach diesem Schritt.','Je termine d’abord cette quête. Demande-moi après cette étape.'],
 ['I am finishing my shop run. Maybe afterward.','Estoy terminando mi actividad de tienda. Quizá después.','Estou terminando minha atividade de loja. Talvez depois.','Ich beende gerade meinen Ladenbesuch. Vielleicht danach.','Je termine mon activité de boutique. Peut-être après.'],
 ['I have a run going already. Check with me after it.','Ya tengo una actividad en curso. Pregúntame después.','Já tenho uma atividade em andamento. Fale comigo depois.','Ich habe schon eine Aufgabe. Frag mich danach.','J’ai déjà une activité en cours. Demande-moi après.'],
 ['No problem. I have not taken or sent anything.','No hay problema. No he recibido ni enviado nada.','Sem problema. Não recebi nem enviei nada.','Kein Problem. Ich habe nichts genommen oder gesendet.','Pas de problème. Je n’ai rien pris ni envoyé.'],
 ['Which item? Link it or show it in trade.','¿Qué objeto? Enlázalo o muéstralo en el intercambio.','Qual item? Envie o link ou mostre na troca.','Welcher Gegenstand? Verlinke ihn oder zeige ihn im Handel.','Quel objet ? Mets son lien ou montre-le dans l’échange.'],
 ['Which item do you mean? Link its item name or put it in the trade window. I will check whether I can use it.','¿Qué objeto quieres decir? Enlaza su nombre o ponlo en el intercambio. Comprobaré si puedo usarlo.','Qual item você quer dizer? Envie o link do nome ou coloque na troca. Vou verificar se posso usá-lo.','Welchen Gegenstand meinst du? Verlinke seinen Namen oder lege ihn ins Handelsfenster. Ich prüfe, ob ich ihn nutzen kann.','De quel objet parles-tu ? Mets le lien de son nom ou place-le dans l’échange. Je vérifierai si je peux l’utiliser.'],
 ['Useful to me. Show it in trade; say free, then confirm.','Me sirve. Muéstralo en el intercambio; di que es gratis y luego confirma.','É útil para mim. Mostre na troca; diga que é grátis e depois confirme.','Das ist für mich nützlich. Zeige es im Handel; sage, dass es kostenlos ist, und bestätige dann.','Il m’est utile. Montre-le dans l’échange ; dis qu’il est gratuit, puis confirme.'],
 ['Thanks, but I will pass. My class, level or equipment requirements do not allow it.','Gracias, pero no. Mi clase, nivel o requisitos de equipo no lo permiten.','Obrigado, mas vou recusar. Minha classe, nível ou requisitos de equipamento não permitem.','Danke, aber ich passe. Meine Klasse, mein Level oder die Ausrüstungsanforderungen erlauben es nicht.','Merci, mais je refuse. Ma classe, mon niveau ou les conditions d’équipement ne le permettent pas.'],
 ['Thanks, but I will pass. That item cannot be offered from your bag.','Gracias, pero no. Ese objeto no se puede ofrecer desde tu bolsa.','Obrigado, mas vou recusar. Esse item não pode ser oferecido da sua bolsa.','Danke, aber ich passe. Dieser Gegenstand kann nicht aus deiner Tasche angeboten werden.','Merci, mais je refuse. Cet objet ne peut pas être proposé depuis ton sac.'],
 ['Thanks, but I will pass. It does not improve my current equipment or fill a supply need.','Gracias, pero no. No mejora mi equipo actual ni cubre una necesidad de suministros.','Obrigado, mas vou recusar. Não melhora meu equipamento atual nem supre uma necessidade.','Danke, aber ich passe. Es verbessert meine Ausrüstung nicht und deckt keinen Vorratsbedarf.','Merci, mais je refuse. Il n’améliore pas mon équipement et ne répond à aucun besoin de provisions.'],
 ['K, accept the party invite when you are ready. I will wait here.','Vale, acepta la invitación cuando estés listo. Esperaré aquí.','Certo, aceite o convite quando estiver pronto. Vou esperar aqui.','Okay, nimm die Gruppeneinladung an, wenn du bereit bist. Ich warte hier.','D’accord, accepte l’invitation quand tu es prêt. J’attends ici.'],
 ['I am not currently in a party.','Ahora no estoy en un grupo.','Não estou em um grupo agora.','Ich bin gerade in keiner Gruppe.','Je ne suis pas dans un groupe actuellement.']
];
// Slots are verbatim captured facts, never translated, formatted or looked up.
const templates=[
 [/^I could use (.+)\. My own buying budget allows up to (\d+) DIL for this offer\. Show it in trade; we both confirm\.$/u,['Podría usar {0}. Mi presupuesto permite hasta {1} DIL por esta oferta. Muéstralo en el intercambio; ambos confirmamos.','Posso usar {0}. Meu orçamento permite até {1} DIL nesta oferta. Mostre na troca; nós dois confirmamos.','Ich könnte {0} nutzen. Mein Budget erlaubt bis zu {1} DIL für dieses Angebot. Zeige es im Handel; wir bestätigen beide.','Je pourrais utiliser {0}. Mon budget permet jusqu’à {1} DIL pour cette offre. Montre-le dans l’échange ; nous confirmons tous les deux.']],
 [/^I could use (.+), but I have no funded buying budget right now\. I will not promise payment I cannot make\.$/u,['Podría usar {0}, pero ahora no tengo presupuesto disponible. No prometeré un pago que no pueda hacer.','Posso usar {0}, mas não tenho orçamento disponível agora. Não prometerei um pagamento que não posso fazer.','Ich könnte {0} nutzen, habe gerade aber kein verfügbares Budget. Ich verspreche keine Zahlung, die ich nicht leisten kann.','Je pourrais utiliser {0}, mais je n’ai pas de budget disponible. Je ne promets pas un paiement que je ne peux pas faire.']],
 [/^I could use (.+)\. Put it in trade and tell me it is free\. Your final confirmation is still required; this conversation transfers nothing\.$/u,['Podría usar {0}. Ponlo en el intercambio y dime que es gratis. Tu confirmación final sigue siendo necesaria; esta conversación no transfiere nada.','Posso usar {0}. Coloque na troca e diga que é grátis. Sua confirmação final ainda é necessária; esta conversa não transfere nada.','Ich könnte {0} nutzen. Lege es ins Handelsfenster und sage, dass es kostenlos ist. Deine abschließende Bestätigung bleibt nötig; dieses Gespräch überträgt nichts.','Je pourrais utiliser {0}. Place-le dans l’échange et dis qu’il est gratuit. Ta confirmation finale reste nécessaire ; cette conversation ne transfère rien.']],
 [/^I could use (.+), but my shop stock is reserved\. Ask after I close the stall\.$/u,['Podría usar {0}, pero los objetos de mi tienda están reservados. Pregúntame cuando cierre.','Posso usar {0}, mas os itens da minha loja estão reservados. Pergunte quando eu fechar.','Ich könnte {0} nutzen, aber meine Ladenware ist reserviert. Frag mich, wenn ich den Laden geschlossen habe.','Je pourrais utiliser {0}, mais les objets de ma boutique sont réservés. Demande-moi après sa fermeture.']],
 [/^I am looking for (.+) x1 for my current equipment\. Show the actual item in a trade; both sides still confirm\.$/u,['Busco {0} x1 para mi equipo actual. Muestra el objeto real en un intercambio; ambas partes deben confirmar.','Procuro {0} x1 para meu equipamento atual. Mostre o item real na troca; os dois lados ainda confirmam.','Ich suche {0} x1 für meine Ausrüstung. Zeige den echten Gegenstand im Handel; beide Seiten müssen bestätigen.','Je cherche {0} x1 pour mon équipement actuel. Montre l’objet réel dans l’échange ; les deux parties doivent confirmer.']],
 [/^I am on (.+)\.$/u,['Estoy en la misión {0}.','Estou na missão {0}.','Ich arbeite an der Quest {0}.','Je fais la quête {0}.']],
 [/^My active quest is (.+)\.$/u,['Mi misión activa es {0}.','Minha missão ativa é {0}.','Meine aktive Quest ist {0}.','Ma quête active est {0}.']],
 [/^I am in (.+)\.$/u,['Estoy en {0}.','Estou em {0}.','Ich bin in {0}.','Je suis à {0}.']],
 [/^My party currently has (\d+) members\.$/u,['Mi grupo tiene {0} miembros.','Meu grupo tem {0} membros.','Meine Gruppe hat derzeit {0} Mitglieder.','Mon groupe compte actuellement {0} membres.']],
 [/^I am level (\d+)\.$/u,['Soy de nivel {0}.','Estou no nível {0}.','Ich bin Level {0}.','Je suis de niveau {0}.']]
];
const output=new Map();for(const row of whole){output.set(row[0],row.slice(1));output.set(row[0].toLowerCase(),row.slice(1));}
const inputs={
 es:{hola:'hello',buenas:'hello','si':'yes',vale:'okay',no:'no','no gracias':'no thanks',ayuda:'help','ayudame':'help',grupo:'party','invitame':'invite me','sigueme':'follow me','ven conmigo':'follow me','no me sigas':'stop following me','espera aqui':'wait here',preparate:'get ready','atrae uno':'pull one to me','quieres objetos':'want items?','necesitas equipo':'need gear?','puedo darte equipo':'can I give you gear?','es gratis':'it is free','que necesitas':'what do you need?','gracias':'thanks'},
 pt:{ola:'hello',oi:'hello',sim:'yes',certo:'okay',nao:'no','nao obrigado':'no thanks',ajuda:'help','me ajude':'help',grupo:'party','me convide':'invite me','me siga':'follow me','venha comigo':'follow me','nao me siga':'stop following me','espere aqui':'wait here','prepare-se':'get ready','atraia um':'pull one to me','quer itens':'want items?','precisa de equipamento':'need gear?','posso dar equipamento':'can I give you gear?','e gratis':'it is free','do que voce precisa':'what do you need?',obrigado:'thanks'},
 de:{hallo:'hello',hi:'hello',ja:'yes',okay:'okay',nein:'no','nein danke':'no thanks',hilfe:'help','hilf mir':'help',gruppe:'party','lade mich ein':'invite me','folge mir':'follow me','komm mit mir':'follow me','folge mir nicht':'stop following me','warte hier':'wait here','mach dich bereit':'get ready','lock einen an':'pull one to me','willst du gegenstande':'want items?','brauchst du ausrustung':'need gear?','kann ich dir ausrustung geben':'can I give you gear?','es ist kostenlos':'it is free','was brauchst du':'what do you need?',danke:'thanks'},
 fr:{bonjour:'hello',salut:'hello',oui:'yes','d accord':'okay',non:'no','non merci':'no thanks',aide:'help','aide moi':'help',groupe:'party','invite moi':'invite me','suis moi':'follow me','viens avec moi':'follow me','ne me suis pas':'stop following me','attends ici':'wait here','prepare toi':'get ready','attire un ennemi':'pull one to me','tu veux des objets':'want items?','tu as besoin d equipement':'need gear?','puis je te donner de l equipement':'can I give you gear?',"c est gratuit":'it is free','de quoi as tu besoin':'what do you need?',merci:'thanks'}
};
const key=s=>s.normalize('NFKD').replace(/[\u0300-\u036f]/g,'').toLowerCase().replace(/[’'-]/g,' ').replace(/^[¿¡]+/,'').replace(/[.!?]+$/g,'').replace(/\s+/g,' ').trim();
const inputTables=new Map(locales.map(code=>[code,new Map(Object.entries(inputs[code]).map(([phrase,text])=>[key(phrase),text]))]));
export function npcNormalizeLocalizedInput(text,code='en') {
  if(typeof text!=='string'||!inputTables.has(code))return text;
  return inputTables.get(code).get(key(text))??text;
}
export function npcLocalizeText(text,code='en') {
  const index=locales.indexOf(code);if(index<0||typeof text!=='string')return text;
  const found=output.get(text);if(found)return found[index];
  for(const [pattern,words]of templates){const match=pattern.exec(text);if(match)return words[index].replace(/\{(\d+)\}/g,(_,i)=>match[Number(i)+1]);}
  // Authored smile style can wrap a recognized phrase, never arbitrary prose.
  if(text.endsWith(' :)')){const base=text.slice(0,-3);for(const ending of ['.','!','?']){const translated=output.get(base+ending);if(translated)return translated[index].replace(/[.!?]$/,'')+' :)';}}
  return text;
}
export function npcLocalizeReply(reply,code='en') {
  if(!reply||typeof reply.text!=='string'||code==='en')return reply;
  const text=npcLocalizeText(reply.text,code);return text===reply.text?reply:{...reply,text};
}
export function npcChatLocalizationCoverage() {
  return {languages:[...NPC_CHAT_LANGUAGES],wholePhrases:whole.length,factualTemplates:templates.length,inputPhrases:Object.fromEntries(locales.map(code=>[code,Object.keys(inputs[code]).length])),fallback:'Unmatched English text is unchanged; no full612-form localization or official language-support claim'};
}
