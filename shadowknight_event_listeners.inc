Sub SHADOWKNIGHT
    /if (${Me.Combat} && ${Me.SpellReady[Dire Stenosis]} && !${Target.Buff[Dire Stenosis].ID}) /casting "Dire Stenosis"
	/if (${Me.Combat} && ${Me.AltAbilityReady[Leech Touch]} && ${Me.PctHPs} < 30) /casting "Leech Touch"
	/if (${Me.Combat} && ${Me.AltAbilityReady[Vicious Bite of Chaos]}) /casting "Vicious Bite of Chaos"
	|/if (${Me.Combat} && !${Target.Buff[Mark of the Zealot].ID}) /call Buff_Request ${Target} ${Spell[Mark of the Zealot].ID} 2
    /call SKBuffs
	/if (${Me.Combat} && ${combat} == 0)                 /call CombatStartSQL	
	/if (!${Me.Combat} && ${combat} == 0)                /call CombatOverSQL
	/if (${Me.Combat} && ${Spawn[${Target.ID}].Fleeing}) /casting "Encroaching Darkness"
	/if (!${Me.Combat} && ${combat} == 1)                /call CombatOverSQL	

/return

Sub CombatStartSQL
  /varset combat 1
  /varset combattarget ${Target.ID}
  /sqlite c:\macroquest2\partystate.db queue update combat set combat = 1, combattarget = ${Target.ID};
  /if ( ${sqlite.clear[queue]} ) {
  } else {
    /echo BOOOOOO
  }
/return

Sub CombatOverSQL
  /varset combat 0
  /varset combattarget 0
  /sqlite c:\macroquest2\partystate.db queue update combat set combat = 0, combattarget = 0;
  /if ( ${sqlite.clear[queue]} ) {
  } else {
    /echo BOOOOOO
  }
/return

Sub SKBuffs
| Buffs from party
	/if (${Me.Combat} && !${Me.Buff[Promised Reformation].ID} ) /call Buff_Request "Phrogeater" ${Spell[Promised Reformation].ID} 2
	|/if (${Me.Combat} && !${Target.Buff[Sha's Legacy].ID}) /call Buff_Request ${Target} ${Spell[Sha's Legacy].ID} 15
    /if (!${Me.Buff[Surge of Arcanum].ID})       /call Buff_Request "Phrogeater" ${Spell[Surge of Arcanum].ID} 13
    /if (!${Me.Buff[Shining Armor].ID})          /call Buff_Request "Phrogeater" ${Spell[Shining Armor].ID} 2
    |/if (!${Me.Buff[Spirit of Tala'Tak].ID})          /call Buff_Request "Phrogeater" ${Spell[Spirit of Tala'Tak].ID} 15
	/if (!${Me.Buff[Olsif's Retort].ID})        /call Buff_Request "Phrogeater" ${Spell[Olsif's Retort].ID} 2
	|/if (!${Me.Buff[Rallied Bastion of Vie].ID}) /call Buff_Request "Phrogeater" ${Spell[Rallied Bastion of Vie].ID} 2
	/if (!${Me.Buff[Flameskin].ID})              /call Buff_Request "Phrogeater" ${Spell[Flameskin].ID} 13
	/if (!${Me.Buff[Molten Veil].ID})            /call Buff_Request "Phrogeater" ${Spell[Molten Veil].ID} 13
	/if (!${Me.Buff[Certitude].ID})              /call Buff_Request "Phrogeater" ${Spell[Unified Hand of Certitude].ID} 2
	|/if (!${Me.Buff[Ferocity of Irionu].ID})     /call Buff_Request "Phrogeater" ${Spell[Ferocity of Irionu].ID} 15
	|/if (!${Me.Buff[Celerity].ID})     /call Buff_Request "Phrogeater" ${Spell[Celerity].ID} 15
| Self buffs
	/if (!${Me.Buff[Bobbing Corpse II].ID} && !${Me.Moving})      /casting "Bobbing Corpse|alt" -invis
	/if (!${Me.Buff[Drape of the Sepulcher].ID} && !${Me.Moving}) /casting "Drape of the Sepulcher" gem11 -invis
	|/if (!${Me.Buff[Ghoul Skin].ID} && !${Me.Moving})             /casting "Ghoul Skin" gem9 -invis
	/if (!${Me.Buff[Dark Bargain].ID} && !${Me.Moving})           /casting "Dark Bargain" gem7 -invis
	|/if (!${Me.Buff[Call of Darkness].ID} && !${Me.Moving})      /casting "Call of Darkness" gem6 -invis
	|/if (!${Me.Buff[Malarian Skin].ID} && !${Me.Moving})         /casting "Malarian Skin" gem5 -invis
	/if (!${Me.Buff[Stoic Stance].ID} && !${Me.Moving}) /casting "Stoic Stance Rk. II" gem8 -invis
| Target enemy curse buffs
	|/if (${Me.Combat} && !${Target.Buff[Mark of the Zealot].ID}) /call Buff_Request ${Target} ${Spell[Mark of the Zealot].ID} 2
	/if (${Me.Combat} && !${Target.Buff[Perfidious Blight].ID}) /casting "Perfidious Blight" gem10
	/if (${Me.Combat} && ${Me.SpellReady[Plague of Klonda]} && !${Target.Buff[Plague of Klonda].ID}) /casting "Plague of Klonda"
    
/return


#event Swarm "<Phrogeater> swarm"
Sub Event_Swarm
  /call Buff_Request "${Target}" ${Spell[Ruthless Servant].ID} 13
/return

#event CombatOver                      "You have slain #*#!"
Sub Event_CombatOver
  /varset combat 0
  /sqlite c:\macroquest2\partystate.db queue update combat set combat = 0, combattarget = ${Me.ID};
  /bc exp
  /if (${sqlite.clear[queue]} == 0) /echo crappy
/return

Sub FinishCasting
  :casting
  /if (${Me.Casting.ID}) /goto :casting
/return



Sub CombatStart
  /varset combat 1
  /varset combattarget ${Target.ID}
  /bc combat start ${combattarget}
/return

Sub CombatOver
  /varset combat 0
  /varset ds 0
  /bc combat over
/return

| server callbacks

Sub DS
  /if (!${Target.Buff[Mark of the Adherent]} && ${ds} == 0 ) {
    /varset ds 1
	/bc ds
  } else {
  }
/return

Sub Buff_Credence
  /varset br 1
  /bc Credence
  /delay 3
/return

Sub Heal
  /bc heal
  /delay 5
/return

Sub Buff_CallOfDarkness
  /cast 9
  /call FinishCasting
/return

Sub Buff_DarkBargain
  /cast 8
  /call FinishCasting
/return

Sub Buff_Request (CHARACTER, theBUFF, classType)
  /sqlite c:\macroquest2\partystate.db queue select * from buffs where character='${CHARACTER}' and buff="${theBUFF}";
  /if (${sqlite.rows[queue]}==0) {
    /sqlite c:\macroquest2\partystate.db queue insert into buffs (character, buff, type) values ('${CHARACTER}', ${Spell[${theBUFF}].ID}, '${classType}');
  } else {
  }
  /if (${sqlite.clear[queue]} == 0) /echo crappy
/return
