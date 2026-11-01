// Original cosmetic designs. Shared by client geometry and the server/shop item
// catalog; deliberately free of renderer, user, inventory or world state.
export const WING_ITEM_BASE = 88010000;
const specs = [
 ['Dawn Eagle','feather','eagle','Broad layered primaries, a swept shoulder and copper quills.',[0xe9d8af,0xc57c36,0xffedb1],1.65,1.1,.45,12],
 ['Moon Owl','feather','owl','Rounded scalloped fans with compact overlapping flight feathers.',[0x626b9e,0xb3bbc9,0xb8ddff],1.3,.85,.8,15],
 ['Storm Swallow','feather','swallow','Long swept spear tips and split trailing streamers.',[0x193c58,0x5fabc4,0xb9f2ff],1.9,.65,1.05,9],
 ['Royal Peacock','feather','peacock','High radial eyespot fans and cascading ornamental plumes.',[0x165b60,0xcaa654,0x66e2c7],1.55,1.6,.5,11],
 ['Ember Phoenix','feather','phoenix','Ascending flame quills with three long trailing feathers.',[0xb73d22,0xf69935,0xffdf89],1.5,1.5,1.1,10],
 ['Obsidian Drake','dragon','drake','Five hooked spars around a deeply scalloped leathery web.',[0x302c42,0x845673,0xea7989],1.7,1.1,.75,5],
 ['Frost Wyvern','dragon','wyvern','Three tall icy fingers and a narrow swept membrane.',[0x638ca0,0xb7dfe6,0xecffff],1.75,1.55,.4,3],
 ['Crimson Bat','dragon','bat','Wide low four-finger webs with forked outer hooks.',[0x672535,0x1f1c2e,0xff6582],1.8,.7,.9,4],
 ['Sand Basilisk','dragon','basilisk','Segmented rib armor over angular six-spoked membranes.',[0xaa8449,0x553c33,0xf2c669],1.6,1.05,.55,6],
 ['Deep Leviathan','dragon','leviathan','Long fin-like webs and curved hanging dorsal spines.',[0x16495e,0x397d88,0x73e6df],1.5,.85,1.3,7],
 ['Monarch Glass','insect','butterfly','Four broad lobes with stained-glass veins and oval windows.',[0xcb6a2b,0x241f34,0xffe4aa],1.4,1.3,.85,7],
 ['Luna Moth','insect','moth','Crescent upper lobes and two long curling hindwing tails.',[0x87bda5,0xc9dab1,0xebffd7],1.45,1.05,1.4,8],
 ['Azure Dragonfly','insect','dragonfly','Two narrow veined blades per side, spaced vertically.',[0x57899d,0x233c53,0x91eeff],1.95,.7,.35,6],
 ['Jewel Scarab','insect','scarab','Domed hard elytra open above small translucent flight fans.',[0x254c77,0xbb9347,0x68cde5],1.2,1,.6,5],
 ['Orchid Cicada','insect','cicada','Long pointed teardrop panels with intricate diagonal veins.',[0xa06d9e,0x4e365e,0xf6c5ea],1.65,1.1,.65,9],
 ['Clockwork Kestrel','machine','clockwork','Jointed brass struts, overlapping metal vanes and gear hubs.',[0xb09a59,0x3e4b53,0xfad77c],1.55,1,.65,8],
 ['Ion Thrusters','machine','thruster','Twin turbine nacelles with three swept stabilizer fins.',[0x516477,0xa3b7c5,0x69e2ff],1.25,.6,.75,3],
 ['Solar Sail','machine','sail','Diamond solar panels on articulated spars with copper gridwork.',[0x263c7d,0xcaa66a,0x88afff],1.65,1.1,.6,4],
 ['Artificer Glider','machine','glider','Rigid delta foil, perforated outriggers and a thin tail boom.',[0xc9b6a2,0x705545,0xf8d4aa],1.95,.55,.75,5],
 ['Magnetic Halo','machine','magnetic','Open horseshoe rails orbiting clustered levitating plates.',[0x455c65,0x9baeba,0x7dffd7],1.4,1.1,.65,7],
 ['Amethyst Cathedral','crystal','cathedral','Tall buttress shards surrounding a broken arch window.',[0x8351a5,0x392855,0xe7b7ff],1.4,1.55,.55,7],
 ['Glacier Spears','crystal','spears','Five long faceted ice lances in an outward radial fan.',[0x89c5d6,0x416881,0xdcffff],1.75,1.2,.75,5],
 ['Ruby Geode','crystal','geode','A compact mineral rim enclosing many irregular crystal teeth.',[0x992f59,0x432537,0xff83af],1.3,.95,.8,12],
 ['Prism Comet','crystal','comet','Swept shards tapering into a long segmented comet tail.',[0x5f8caf,0xe5b882,0xa5ffec],1.8,.85,1.05,9],
 ['Quartz Antlers','crystal','antlers','Branching crystalline arms with open gaps and tiny prism buds.',[0xb6b5c8,0x625b86,0xf1edff],1.55,1.6,.3,6],
 ['Verdant Fern','botanical','fern','Curved fronds lined with alternate miniature leaflets.',[0x3c875b,0x8fc380,0xc4f7aa],1.5,1.3,.7,9],
 ['Autumn Maple','botanical','maple','Broad five-point leaves on woody branching stems.',[0xb95436,0x764437,0xffc36e],1.45,1.15,.8,5],
 ['Lotus Petals','botanical','lotus','Two tiers of smooth cupped petals around a golden seed clasp.',[0xd68bb5,0x668d76,0xffd8ea],1.3,1.2,.55,7],
 ['Thorn Rose','botanical','rose','Open thorn-vine loops framing serrated rose leaves and buds.',[0x84364a,0x315c4d,0xec9ab8],1.45,1.15,.9,6],
 ['Silver Willow','botanical','willow','Drooping silver leaves strung from long arched branches.',[0x91bdb5,0x536c7a,0xd9fff1],1.7,.85,1.25,13],
 ['Seraph Sunwheel','celestial','sunwheel','An open radiant wheel with alternating long and short rays.',[0xebbf69,0x9c703c,0xfff0ae],1.4,1.35,.7,12],
 ['Crescent Oracle','celestial','crescent','Large open moons, inner star talismans and hanging chains.',[0xb2bed4,0x666688,0xe3eaff],1.3,1.4,1,6],
 ['Astral Orrery','celestial','orrery','Intersecting elliptical rings carrying small orbiting stars.',[0x7188ba,0xa48b60,0xaad8ff],1.5,1.25,.6,4],
 ['Constellation Lace','celestial','constellation','An airy star-node lattice with asymmetric branching rays.',[0x7894b0,0x394866,0xc2ecff],1.7,1.25,.7,10],
 ['Eclipse Blades','celestial','eclipse','Two interrupted dark halos backed by a sharp radial corona.',[0x3c365a,0xc4936a,0xe4c4ff],1.5,1.3,.9,9],
 ['Pearl Manta','aquatic','manta','Wide curved ray fins with a soft belly seam and long trailing barbs.',[0x5e93a1,0xd2c8b5,0xa8eaf0],1.85,.6,.9,6],
 ['Coral Reef','aquatic','coral','Branched coral fingers carrying rounded luminous polyps.',[0xd78070,0x825276,0xffcba6],1.45,1.3,.65,8],
 ['Nautilus Scroll','aquatic','nautilus','Open spiral shells and alternating segmented shell ribs.',[0xcbb6a1,0x697a95,0xf1dcc4],1.4,1.2,.8,9],
 ['Lionfish Crown','aquatic','lionfish','Long striped spines stretched across a tapered fin web.',[0x9e664d,0xe3cfac,0xffe3b7],1.7,1.2,.9,11],
 ['Abyss Jellyveil','aquatic','jelly','Scalloped bell fans above hanging beaded ribbon tentacles.',[0x695b9c,0x368595,0x9aefed],1.35,1,.95,7],
 ['Ghost Lantern','spectral','lantern','Floating ribbon loops framing paired luminous lantern cores.',[0x67a198,0x344459,0xb1ffe0],1.35,1.2,.8,6],
 ['Soulfire Arcs','spectral','fire','Forked flame ribbons reaching high with sharp flickering tips.',[0x4c77b6,0x34345e,0x94e5ff],1.55,1.5,.85,7],
 ['Void Ribbons','spectral','ribbon','Three woven bands with cut-out spaces and long twisting ends.',[0x624ba1,0x2b254c,0xc8abff],1.8,.85,1.15,3],
 ['Dreamcatcher','spectral','dream','Open webbed hoops, hanging crystal beads and gauzy tails.',[0xba88b8,0x566581,0xffd2f1],1.35,1.2,1.05,8],
 ['Tempest Spiral','spectral','spiral','Three sweeping spiral arms studded with lightning shards.',[0x5b8bb0,0x4c566e,0xb9f2ff],1.65,1.35,.8,3],
 ['Paladin Aegis','heraldic','aegis','Layered scalloped shield feathers edged with heraldic gold.',[0xb4cad4,0xb89b55,0xf9e7ae],1.55,1.1,.7,7],
 ['Runeblade Choir','heraldic','runeblade','Six floating sword-shaped vanes with recessed rune channels.',[0x667b99,0x292f4b,0xa0d1ff],1.6,1.35,.6,6],
 ['Crimson Standard','heraldic','standard','Tall banner sails on gilded pole arms with forked cloth tails.',[0x9a3646,0xcaa65c,0xffce91],1.35,1.5,1,4],
 ['Onyx Raven','heraldic','raven','Razor-edged overlapping black plates with a hooked crest.',[0x303344,0x6d6786,0xc4aee7],1.7,1.05,.85,10],
 ['Tournament Laurels','heraldic','laurel','Open victory wreaths carrying alternating leaf medals.',[0xb5a165,0x5c7757,0xffe9a6],1.45,1.25,.8,12],
];
const motionStyles=['soar','beat','sweep','fan','cascade'];
const glowStyles=['flow','ripple','spark','orbit','breathe'];
export const WING_DESIGNS = Object.freeze(specs.map(([name,family,form,description,palette,span,rise,drop,count],i)=>Object.freeze({id:i+1,name,description,family,form,palette:Object.freeze(palette),span,rise,drop,count,flutter:.65+(i%5)*.075,
 motion:Object.freeze({style:motionStyles[i%5],frequency:.55+(i%7)*.09,flap:.1+(i%5)*.025,sweep:.02+(i%4)*.012,ripple:.025+(i%6)*.006}),
 glow:Object.freeze({style:glowStyles[(Math.floor(i/5)+i%5)%5],speed:.65+(i%9)*.11,intensity:.62+(i%5)*.06,description:`${form} ${glowStyles[(Math.floor(i/5)+i%5)%5]} through authored luminous details`})
})));
export function wingAssetKey(id) { return Number.isInteger(id)&&id>=1&&id<=WING_DESIGNS.length?`engine/wings/${id}.wing`:null; }
export function parseWingAssetKey(key) { const m=/^engine\/wings\/([1-9]\d?)\.wing$/.exec(String(key));const id=m?Number(m[1]):0;return id>=1&&id<=WING_DESIGNS.length?id:null; }
export function wingDesignForItem(item) { const id=Number(item)-WING_ITEM_BASE;return Number.isInteger(id)?WING_DESIGNS[id-1]||null:null; }
