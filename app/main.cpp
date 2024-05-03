#include <iostream>
#include "../code/Tries.h"

using namespace std;

set <char> createAlphabetSet(){
  set<char> alphabet;
  for(char c = 'a'; c <= 'z';c++){
    alphabet.insert(c);
  }
  return alphabet;
}

void create_trie_from_paragraph(string text, Tries &my_trie){
  string word = "";
  string c = "";
  for(int i = 0; i < text.size(); i++){
    c = tolower(text[i]);
    if(my_trie.alphabet.find(tolower(text[i])) != my_trie.alphabet.end()){
      word += c;
    }
    else {
      my_trie.insert(word);
      word = "";
    }
  }
  return;
}

string text = R"(Stay for me there! I will not fail.

To meet thee in that hollow vale.

 

(Exequy on the death of his wife, by Henry King, Bishop of Chichester.)

 

Ill-fated and mysterious man!—bewildered in the brilliancy of thine own imagination, and fallen in the flames of thine own youth! Again in fancy I behold thee! Once more thy form hath risen before me!—not—oh! not as thou art—in the cold valley and shadow—but as thou shouldst be—squandering away a life of magnificent meditation in that city of dim visions, thine own Venice—which is a star-beloved Elysium of the sea, and the wide windows of whose Palladian palaces look down with a deep and bitter meaning upon the secrets of her silent waters. Yes! I repeat it—as thou shouldst be. There are surely other worlds than this—other thoughts than the thoughts of the multitude—other speculations than the speculations of the sophist. Who then shall call thy conduct into question? who blame thee for thy visionary hours, or denounce those occupations as a wasting away of life, which were but the overflowings of thine everlasting energies?

It was at Venice, beneath the covered archway there called the Ponte di Sospiri, that I met for the third or fourth time the person of whom I speak. It is with a confused recollection that I bring to mind the circumstances of that meeting. Yet I remember—ah! how should I forget?—the deep midnight, the Bridge of Sighs, the beauty of woman, and the Genius of Romance that stalked up and down the narrow canal.

It was a night of unusual gloom. The great clock of the Piazza had sounded the fifth hour of the Italian evening. The square of the Campanile lay silent and deserted, and the lights in the old Ducal Palace were dying fast away. I was returning home from the Piazetta, by way of the Grand Canal. But as my gondola arrived opposite the mouth of the canal San Marco, a female voice from its recesses broke suddenly upon the night, in one wild, hysterical, and long continued shriek. Startled at the sound, I sprang upon my feet: while the gondolier, letting slip his single oar, lost it in the pitchy darkness beyond a chance of recovery, and we were consequently left to the guidance of the current which here sets from the greater into the smaller channel. Like some huge and sable-feathered condor, we were slowly drifting down towards the Bridge of Sighs, when a thousand flambeaux flashing from the windows, and down the staircases of the Ducal Palace, turned all at once that deep gloom into a livid and preternatural day.

A child, slipping from the arms of its own mother, had fallen from an upper window of the lofty structure into the deep and dim canal. The quiet waters had closed placidly over their victim; and, although my own gondola was the only one in sight, many a stout swimmer, already in the stream, was seeking in vain upon the surface, the treasure which was to be found, alas! only within the abyss. Upon the broad black marble flagstones at the entrance of the palace, and a few steps above the water, stood a figure which none who then saw can have ever since forgotten. It was the Marchesa Aphrodite—the adoration of all Venice—the gayest of the gay—the most lovely where all were beautiful—but still the young wife of the old and intriguing Mentoni, and the mother of that fair child, her first and only one, who now, deep beneath the murky water, was thinking in bitterness of heart upon her sweet caresses, and exhausting its little life in struggles to call upon her name.

She stood alone. Her small, bare, and silvery feet gleamed in the black mirror of marble beneath her. Her hair, not as yet more than half loosened for the night from its ball-room array, clustered, amid a shower of diamonds, round and round her classical head, in curls like those of the young hyacinth. A snowy-white and gauze-like drapery seemed to be nearly the sole covering to her delicate form; but the mid-summer and midnight air was hot, sullen, and still, and no motion in the statue-like form itself, stirred even the folds of that raiment of very vapor which hung around it as the heavy marble hangs around the Niobe. Yet—strange to say!—her large lustrous eyes were not turned downwards upon that grave wherein her brightest hope lay buried—but riveted in a widely different direction! The prison of the Old Republic is, I think, the stateliest building in all Venice—but how could that lady gaze so fixedly upon it, when beneath her lay stifling her only child? Yon dark, gloomy niche, too, yawns right opposite her chamber window—what, then, could there be in its shadows—in its architecture—in its ivy-wreathed and solemn cornices—that the Marchesa di Mentoni had not wondered at a thousand times before? Nonsense!—Who does not remember that, at such a time as this, the eye, like a shattered mirror, multiplies the images of its sorrow, and sees in innumerable far-off places, the woe which is close at hand?

Many steps above the Marchesa, and within the arch of the water-gate, stood, in full dress, the Satyr-like figure of Mentoni himself. He was occasionally occupied in thrumming a guitar, and seemed ennuye to the very death, as at intervals he gave directions for the recovery of his child. Stupefied and aghast, I had myself no power to move from the upright position I had assumed upon first hearing the shriek, and must have presented to the eyes of the agitated group a spectral and ominous appearance, as with pale countenance and rigid limbs, I floated down among them in that funereal gondola.

All efforts proved in vain. Many of the most energetic in the search were relaxing their exertions, and yielding to a gloomy sorrow. There seemed but little hope for the child; (how much less than for the mother!) but now, from the interior of that dark niche which has been already mentioned as forming a part of the Old Republican prison, and as fronting the lattice of the Marchesa, a figure muffled in a cloak, stepped out within reach of the light, and, pausing a moment upon the verge of the giddy descent, plunged headlong into the canal. As, in an instant afterwards, he stood with the still living and breathing child within his grasp, upon the marble flagstones by the side of the Marchesa, his cloak, heavy with the drenching water, became unfastened, and, falling in folds about his feet, discovered to the wonder-stricken spectators the graceful person of a very young man, with the sound of whose name the greater part of Europe was then ringing.

No word spoke the deliverer. But the Marchesa! She will now receive her child—she will press it to her heart—she will cling to its little form, and smother it with her caresses. Alas! another’s arms have taken it from the stranger—another’s arms have taken it away, and borne it afar off, unnoticed, into the palace! And the Marchesa! Her lip—her beautiful lip trembles; tears are gathering in her eyes—those eyes which, like Pliny’s acanthus, are “soft and almost liquid.” Yes! tears are gathering in those eyes—and see! the entire woman thrills throughout the soul, and the statue has started into life! The pallor of the marble countenance, the swelling of the marble bosom, the very purity of the marble feet, we behold suddenly flushed over with a tide of ungovernable crimson; and a slight shudder quivers about her delicate frame, as a gentle air at Napoli about the rich silver lilies in the grass.

Why should that lady blush! To this demand there is no answer—except that, having left, in the eager haste and terror of a mother’s heart, the privacy of her own boudoir, she has neglected to enthral her tiny feet in their slippers, and utterly forgotten to throw over her Venetian shoulders that drapery which is their due. What other possible reason could there have been for her so blushing?—for the glance of those wild appealing eyes?—for the unusual tumult of that throbbing bosom?—for the convulsive pressure of that trembling hand?—that hand which fell, as Mentoni turned into the palace, accidentally, upon the hand of the stranger. What reason could there have been for the low—the singularly low tone of those unmeaning words which the lady uttered hurriedly in bidding him adieu? “Thou hast conquered,” she said, or the murmurs of the water deceived me; “thou hast conquered—one hour after sunrise—we shall meet—so let it be!”

 

The tumult had subsided, the lights had died away within the palace, and the stranger, whom I now recognized, stood alone upon the flags. He shook with inconceivable agitation, and his eye glanced around in search of a gondola. I could not do less than offer him the service of my own; and he accepted the civility. Having obtained an oar at the water-gate, we proceeded together to his residence, while he rapidly recovered his self-possession, and spoke of our former slight acquaintance in terms of great apparent cordiality.

There are some subjects upon which I take pleasure in being minute. The person of the stranger—let me call him by this title, who to all the world was still a stranger—the person of the stranger is one of these subjects. In height he might have been below rather than above the medium size: although there were moments of intense passion when his frame actually expanded and belied the assertion. The light, almost slender symmetry of his figure, promised more of that ready activity which he evinced at the Bridge of Sighs, than of that Herculean strength which he has been known to wield without an effort, upon occasions of more dangerous emergency. With the mouth and chin of a deity—singular, wild, full, liquid eyes, whose shadows varied from pure hazel to intense and brilliant jet—and a profusion of curling, black hair, from which a forehead of unusual breadth gleamed forth at intervals all light and ivory—his were features than which I have seen none more classically regular, except, perhaps, the marble ones of the Emperor Commodus. Yet his countenance was, nevertheless, one of those which all men have seen at some period of their lives, and have never afterwards seen again. It had no peculiar, it had no settled predominant expression to be fastened upon the memory; a countenance seen and instantly forgotten, but forgotten with a vague and never-ceasing desire of recalling it to mind. Not that the spirit of each rapid passion failed, at any time, to throw its own distinct image upon the mirror of that face—but that the mirror, mirror-like, retained no vestige of the passion, when the passion had departed.

Upon leaving him on the night of our adventure, he solicited me, in what I thought an urgent manner, to call upon him very early the next morning. Shortly after sunrise, I found myself accordingly at his Palazzo, one of those huge structures of gloomy, yet fantastic pomp, which tower above the waters of the Grand Canal in the vicinity of the Rialto. I was shown up a broad winding staircase of mosaics, into an apartment whose unparalleled splendor burst through the opening door with an actual glare, making me blind and dizzy with luxuriousness.

I knew my acquaintance to be wealthy. Report had spoken of his possessions in terms which I had even ventured to call terms of ridiculous exaggeration. But as I gazed about me, I could not bring myself to believe that the wealth of any subject in Europe could have supplied the princely magnificence which burned and blazed around.

Although, as I say, the sun had arisen, yet the room was still brilliantly lighted up. I judge from this circumstance, as well as from an air of exhaustion in the countenance of my friend, that he had not retired to bed during the whole of the preceding night. In the architecture and embellishments of the chamber, the evident design had been to dazzle and astound. Little attention had been paid to the decora of what is technically called keeping, or to the proprieties of nationality. The eye wandered from object to object, and rested upon none—neither the grotesques of the Greek painters, nor the sculptures of the best Italian days, nor the huge carvings of untutored Egypt. Rich draperies in every part of the room trembled to the vibration of low, melancholy music, whose origin was not to be discovered. The senses were oppressed by mingled and conflicting perfumes, reeking up from strange convolute censers, together with multitudinous flaring and flickering tongues of emerald and violet fire. The rays of the newly risen sun poured in upon the whole, through windows, formed each of a single pane of crimson-tinted glass. Glancing to and fro, in a thousand reflections, from curtains which rolled from their cornices like cataracts of molten silver, the beams of natural glory mingled at length fitfully with the artificial light, and lay weltering in subdued masses upon a carpet of rich, liquid-looking cloth of Chili gold.

“Ha! ha! ha!—ha! ha! ha!”—laughed the proprietor, motioning me to a seat as I entered the room, and throwing himself back at full-length upon an ottoman. “I see,” said he, perceiving that I could not immediately reconcile myself to the bienseance of so singular a welcome—“I see you are astonished at my apartment—at my statues—my pictures—my originality of conception in architecture and upholstery! absolutely drunk, eh, with my magnificence? But pardon me, my dear sir, (here his tone of voice dropped to the very spirit of cordiality,) pardon me for my uncharitable laughter. You appeared so utterly astonished. Besides, some things are so completely ludicrous, that a man must laugh or die. To die laughing, must be the most glorious of all glorious deaths! Sir Thomas More—a very fine man was Sir Thomas More—Sir Thomas More died laughing, you remember. Also in the Absurdities of Ravisius Textor, there is a long list of characters who came to the same magnificent end. Do you know, however,” continued he musingly, “that at Sparta (which is now Palæochori,) at Sparta, I say, to the west of the citadel, among a chaos of scarcely visible ruins, is a kind of socle, upon which are still legible the letters ΛΑΞΜ. They are undoubtedly part of ΓΕΛΑΞΜΑ. Now, at Sparta were a thousand temples and shrines to a thousand different divinities. How exceedingly strange that the altar of Laughter should have survived all the others! But in the present instance,” he resumed, with a singular alteration of voice and manner, “I have no right to be merry at your expense. You might well have been amazed. Europe cannot produce anything so fine as this, my little regal cabinet. My other apartments are by no means of the same order—mere ultras of fashionable insipidity. This is better than fashion—is it not? Yet this has but to be seen to become the rage—that is, with those who could afford it at the cost of their entire patrimony. I have guarded, however, against any such profanation. With one exception, you are the only human being besides myself and my valet, who has been admitted within the mysteries of these imperial precincts, since they have been bedizened as you see!”

I bowed in acknowledgment—for the overpowering sense of splendor and perfume, and music, together with the unexpected eccentricity of his address and manner, prevented me from expressing, in words, my appreciation of what I might have construed into a compliment.

“Here,” he resumed, arising and leaning on my arm as he sauntered around the apartment, “here are paintings from the Greeks to Cimabue, and from Cimabue to the present hour. Many are chosen, as you see, with little deference to the opinions of Virtu. They are all, however, fitting tapestry for a chamber such as this. Here, too, are some chefs d’oeuvre of the unknown great; and here, unfinished designs by men, celebrated in their day, whose very names the perspicacity of the academies has left to silence and to me. What think you,” said he, turning abruptly as he spoke—“what think you of this Madonna della Pieta?”

“It is Guido’s own!” I said, with all the enthusiasm of my nature, for I had been poring intently over its surpassing loveliness. “It is Guido’s own!—how could you have obtained it?—she is undoubtedly in painting what the Venus is in sculpture.”

“Ha!” said he thoughtfully, “the Venus—the beautiful Venus?—the Venus of the Medici?—she of the diminutive head and the gilded hair? Part of the left arm (here his voice dropped so as to be heard with difficulty,) and all the right, are restorations; and in the coquetry of that right arm lies, I think, the quintessence of all affectation. Give me the Canova! The Apollo, too, is a copy—there can be no doubt of it—blind fool that I am, who cannot behold the boasted inspiration of the Apollo! I cannot help—pity me!—I cannot help preferring the Antinous. Was it not Socrates who said that the statuary found his statue in the block of marble? Then Michael Angelo was by no means original in his couplet—

 

’Non ha l’ottimo artista alcun concetto

Che un marmo solo in se non circunscriva.’”

 

It has been, or should be remarked, that, in the manner of the true gentleman, we are always aware of a difference from the bearing of the vulgar, without being at once precisely able to determine in what such difference consists. Allowing the remark to have applied in its full force to the outward demeanor of my acquaintance, I felt it, on that eventful morning, still more fully applicable to his moral temperament and character. Nor can I better define that peculiarity of spirit which seemed to place him so essentially apart from all other human beings, than by calling it a habit of intense and continual thought, pervading even his most trivial actions—intruding upon his moments of dalliance—and interweaving itself with his very flashes of merriment—like adders which writhe from out the eyes of the grinning masks in the cornices around the temples of Persepolis.

I could not help, however, repeatedly observing, through the mingled tone of levity and solemnity with which he rapidly descanted upon matters of little importance, a certain air of trepidation—a degree of nervous unction in action and in speech—an unquiet excitability of manner which appeared to me at all times unaccountable, and upon some occasions even filled me with alarm. Frequently, too, pausing in the middle of a sentence whose commencement he had apparently forgotten, he seemed to be listening in the deepest attention, as if either in momentary expectation of a visitor, or to sounds which must have had existence in his imagination alone.

It was during one of these reveries or pauses of apparent abstraction, that, in turning over a page of the poet and scholar Politian’s beautiful tragedy “The Orfeo,” (the first native Italian tragedy,) which lay near me upon an ottoman, I discovered a passage underlined in pencil. It was a passage towards the end of the third act—a passage of the most heart-stirring excitement—a passage which, although tainted with impurity, no man shall read without a thrill of novel emotion—no woman without a sigh. The whole page was blotted with fresh tears; and, upon the opposite interleaf, were the following English lines, written in a hand so very different from the peculiar characters of my acquaintance, that I had some difficulty in recognising it as his own:—

 

Thou wast that all to me, love,

    For which my soul did pine—

A green isle in the sea, love,

    A fountain and a shrine,

All wreathed with fairy fruits and flowers;

    And all the flowers were mine.

 

Ah, dream too bright to last!

    Ah, starry Hope, that didst arise

But to be overcast!

    A voice from out the Future cries,

“Onward!”—but o’er the Past

    (Dim gulf!) my spirit hovering lies,

Mute—motionless—aghast!

 

For alas! alas! with me

    The light of life is o’er.

“No more—no more—no more,”

    (Such language holds the solemn sea

To the sands upon the shore,)

    Shall bloom the thunder-blasted tree,

Or the stricken eagle soar!

 

Now all my hours are trances;

    And all my nightly dreams

Are where the dark eye glances,

    And where thy footstep gleams,

In what ethereal dances,

    By what Italian streams.

 

Alas! for that accursed time

    They bore thee o’er the billow,

From Love to titled age and crime,

    And an unholy pillow!—

From me, and from our misty clime,

    Where weeps the silver willow!

 

That these lines were written in English—a language with which I had not believed their author acquainted—afforded me little matter for surprise. I was too well aware of the extent of his acquirements, and of the singular pleasure he took in concealing them from observation, to be astonished at any similar discovery; but the place of date, I must confess, occasioned me no little amazement. It had been originally written London, and afterwards carefully overscored—not, however, so effectually as to conceal the word from a scrutinizing eye. I say, this occasioned me no little amazement; for I well remember that, in a former conversation with a friend, I particularly inquired if he had at any time met in London the Marchesa di Mentoni, (who for some years previous to her marriage had resided in that city,) when his answer, if I mistake not, gave me to understand that he had never visited the metropolis of Great Britain. I might as well here mention, that I have more than once heard, (without, of course, giving credit to a report involving so many improbabilities,) that the person of whom I speak, was not only by birth, but in education, an Englishman.

 

“There is one painting,” said he, without being aware of my notice of the tragedy—“there is still one painting which you have not seen.” And throwing aside a drapery, he discovered a full-length portrait of the Marchesa Aphrodite.

Human art could have done no more in the delineation of her superhuman beauty. The same ethereal figure which stood before me the preceding night upon the steps of the Ducal Palace, stood before me once again. But in the expression of the countenance, which was beaming all over with smiles, there still lurked (incomprehensible anomaly!) that fitful stain of melancholy which will ever be found inseparable from the perfection of the beautiful. Her right arm lay folded over her bosom. With her left she pointed downward to a curiously fashioned vase. One small, fairy foot, alone visible, barely touched the earth; and, scarcely discernible in the brilliant atmosphere which seemed to encircle and enshrine her loveliness, floated a pair of the most delicately imagined wings. My glance fell from the painting to the figure of my friend, and the vigorous words of Chapman’s Bussy D’Ambois, quivered instinctively upon my lips:

 

    “He is up

There like a Roman statue! He will stand

Till Death hath made him marble!”

 

“Come,” he said at length, turning towards a table of richly enamelled and massive silver, upon which were a few goblets fantastically stained, together with two large Etruscan vases, fashioned in the same extraordinary model as that in the foreground of the portrait, and filled with what I supposed to be Johannisberger. “Come,” he said, abruptly, “let us drink! It is early—but let us drink. It is indeed early,” he continued, musingly, as a cherub with a heavy golden hammer made the apartment ring with the first hour after sunrise: “It is indeed early—but what matters it? let us drink! Let us pour out an offering to yon solemn sun which these gaudy lamps and censers are so eager to subdue!” And, having made me pledge him in a bumper, he swallowed in rapid succession several goblets of the wine.

“To dream,” he continued, resuming the tone of his desultory conversation, as he held up to the rich light of a censer one of the magnificent vases—“to dream has been the business of my life. I have therefore framed for myself, as you see, a bower of dreams. In the heart of Venice could I have erected a better? You behold around you, it is true, a medley of architectural embellishments. The chastity of Ionia is offended by antediluvian devices, and the sphynxes of Egypt are outstretched upon carpets of gold. Yet the effect is incongruous to the timid alone. Proprieties of place, and especially of time, are the bugbears which terrify mankind from the contemplation of the magnificent. Once I was myself a decorist; but that sublimation of folly has palled upon my soul. All this is now the fitter for my purpose. Like these arabesque censers, my spirit is writhing in fire, and the delirium of this scene is fashioning me for the wilder visions of that land of real dreams whither I am now rapidly departing.” He here paused abruptly, bent his head to his bosom, and seemed to listen to a sound which I could not hear. At length, erecting his frame, he looked upwards, and ejaculated the lines of the Bishop of Chichester:

 

“Stay for me there! I will not fail

To meet thee in that hollow vale.”

 

In the next instant, confessing the power of the wine, he threw himself at full-length upon an ottoman.

A quick step was now heard upon the staircase, and a loud knock at the door rapidly succeeded. I was hastening to anticipate a second disturbance, when a page of Mentoni’s household burst into the room, and faltered out, in a voice choking with emotion, the incoherent words, “My mistress!—my mistress!—Poisoned!—poisoned! Oh, beautiful—oh, beautiful Aphrodite!”

Bewildered, I flew to the ottoman, and endeavored to arouse the sleeper to a sense of the startling intelligence. But his limbs were rigid—his lips were livid—his lately beaming eyes were riveted in death. I staggered back towards the table—my hand fell upon a cracked and blackened goblet—and a consciousness of the entire and terrible truth flashed suddenly over my soul.)";

void demo(){
  set<char> alphabet = createAlphabetSet();
  Tries my_trie(alphabet);

  my_trie.insert("mike");
  cout << "mike inserted, Report: " << my_trie.report() << endl;
  my_trie.insert("mitch");
  cout << "mitch inserted, Report: " << my_trie.report() << endl;
  my_trie.insert("max");
  cout << "max inserted, Report: " <<my_trie.report() << endl;
  my_trie.insert("steve");
  cout << "steve inserted, Report: " <<my_trie.report() << endl;
  my_trie.insert("frank");
  cout << "frank inserted, Report: " <<my_trie.report() << endl;


  cout << "number of words: " << my_trie.num_words << endl;
  cout << "remove mitch" << endl;
  my_trie.remove("mitch");
  cout << "number of words: " << my_trie.num_words << endl;
  cout << "Report: " <<my_trie.report() << endl;

  cout << "Example of printing a node's information:" << endl;
  cout << my_trie.print_node(my_trie.get_root());

  cout << "The End" << endl;

}

void demo2(){
    set<char> alphabet = createAlphabetSet();
  Tries my_trie(alphabet);

  my_trie.insert("mitch");
  my_trie.insert("mike");
  my_trie.compress_trie(my_trie.get_root());

  trie_node* cursor = my_trie.get_root();

  for(auto pair = cursor->map.begin(); pair != cursor->map.end(); pair++){
    cout << my_trie.print_node(pair->second) << endl;
  }

  cursor = cursor->map.at("mi");
    for(auto pair = cursor->map.begin(); pair != cursor->map.end(); pair++){
    cout << my_trie.print_node(pair->second) << endl;
  }
}

void demo3(string text){
  set<char> alphabet = createAlphabetSet();
  Tries my_trie(alphabet);

  create_trie_from_paragraph(text,my_trie);

  cout << "number of characters: " << my_trie.num_characters << endl;
  cout << "number of words: " << my_trie.num_words << endl;
  cout << "number of nodes: " << my_trie.num_nodes << endl;


  my_trie.compress_trie(my_trie.get_root());

  cout << "COMPRESSING" << endl;

  cout << "number of characters: " << my_trie.num_characters << endl;
  cout << "number of words: " << my_trie.num_words << endl;
  cout << "number of nodes: " << my_trie.num_nodes << endl;

  double denom = my_trie.num_characters;
  double numerator = my_trie.num_nodes;

  double ratio = numerator / denom;

  cout << "You save " << to_string(1 - ratio) << "\% space by compressing the trie" << endl;
  }


int main(){
  cout << "\n ___________________Demonstrating a standard Trie\n" << endl;
  demo();
  cout << "\n ___________________Demonstrating a compressed Trie\n" << endl;
  demo2();
  cout << "\n ___________________Demonstrating saving space with a compressed Trie\n" << endl;
  demo3(text);

  return 0;
}