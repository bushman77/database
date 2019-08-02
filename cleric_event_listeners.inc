Sub CLERIC
	/call Roster
/return

Sub Roster
  /declare x int local
  /for x 0 to 5
   /if (${Group.Member[${x}].ID}) {
     /if ( ${Group.Member[${x}].PctHPs} < 86 ) {
	   /target ${Group.Member[${x}]}
	   /casting "Reverent Light" gem5
	 } else {
	 }
   } else {
   }
  /next x
  /delay 1
/return


#event Pacify "<Phrogeater> pacify #1#"
Sub Event_Pacify(Line, TARGET)
  /target ${Spawn[${TARGET}]}
  
  :PacifyLoop
      /if (${Target.Distance}>190) /keypress w hold
      /if (${Target.Distance}<190) /keypress w 
      /face fast
      /delay 1
   /if (${Target.ID} && ${Target.Distance}>190) /goto :PacifyLoop
  /casting "Soothing Glow" gem11
  /call FinishCasting
/return 

#event ToMe "<Phrogeater> tome"
Sub Event_ToMe
:Loop
      /if (${Target.Distance}>20) /keypress w hold
      /if (${Target.Distance}<20) /keypress w 
      /face fast
      /delay 1
   /if (${Target.ID} && ${Target.Distance}>20) /goto :Loop
   /if (${Target.Distance}<20) /keypress w 
/return

#event Ageo                     "Your Certitude spell has worn off of #1#"
Sub Event_Ageo(Line, TARGET)
  /target ${TARGET}
  /cast 10
  /call FinishCasting
/return

#event ArmorOfVie               "Your Armor of Vie spell has worn off of #1#."
Sub Event_ArmorOfVie(Line, TARGET)
  /target ${TARGET}
  /cast 12
  /call FinishCasting
/return

#event Assist                   "<Phrogeater> assist #1#"
Sub Event_Assist(Line, T)
  /target ${Spawn[${combattarget}]}
  /delay 1
  /if (!${Target.Buff[Mark of Zealot]) /casting "Mark of the Zealot" gem3
  /call FinishCasting
/return

#event Undead                   "<Phrogeater> undead #1#"
Sub Event_Undead(Line, target}
  /target ${Spawn[${target}]}
  /delay 1
  /cast 7
  /call FinishCasting
/return

#event Credence				    "<#1#> credence"
Sub Event_Credence(Line, TARGET)
  /target ${TARGET}
  /delay 1
  /casting "Unified Hand of Certitude" gem10
  /call FinishCasting
/return

#event CombatStart              "<Phrogeater> combat start #1#"
Sub Event_CombatStart(Line, TARGET)
  /varset combat 1
  /varset combattarget ${TARGET}
/return

#event CombatOver               "<Phrogeater> combat over"
Sub Event_CombatOver
  /varset combat 0
  /varset combattarget 0
/return

#event DoTHeal				    "<Phrogeater> dotheal"
Sub Event_DoTHeal
  /if (${Me.Class.ID} == 2) /cast 2
  /call FinishCasting
/return

#event GalvosRetort             "Your Galvos Retort spell has worn off of #1#."
Sub Event_GalvosRetort(Line, TARGET)
  /target ${TARGET}
  /delay 1
  /cast 12
  /call FinishCasting
/return

#event Heal				        "<Phrogeater> heal"
Sub Event_Heal
  /casting "Word of Renewal" gem1
  /call FinishCasting
/return

#event Invite                   "Phrogeater invites you to join a group."
Sub Event_Invite
  /keypress ctrl+i
/return

#event Promise                  "<Phrogeater> promise"
Sub Event_Promise
  /target ${Spawn[${watch}]}
  /delay 1
  /cast 5
  /call FinishCasting
/return

#event ReverseDS                "<Phrogeater> ds #1#"
Sub Event_ReverseDS(Line, TARGET)
  /target ${Spawn[${TARGET}]}
  /cast 3
  /call FinishCasting
/return

#event ShiningArmor	    		"<Phrogeater> Shining Armor"
Sub Event_ShiningArmor
  |/target Phrogeater
  /target ${Spawn[${watch}]}
  /cast 4
  /call FinishCasting
/return

#event WatchTarget	    		"<#1#> watch #2#"
Sub Event_WatchTarget(Line, CALLER, TARGET)
  /echo ${Spawn[${TARGET}]}
  /varset watch ${TARGET}
/return

Sub Buffs
  /if (${Me.Buff[Summon Corrputed Sokokar].ID} == 0 ) /casting "Bridle of the Corrputed Sokokar" item
  |/if (!${Me.Buff[Certitude].ID}) /call Ageo  
/return
Sub Ageo
  /targ ${Spawn[${watch}]}
  /casting "Unified Certitude" gem6 -invis
/return


Sub Watch
  /doevents
  /target ${Spawn[${watch}]}
  /if (${Target.PctHPs} < 85 ) /casting "Reverent Light" gem5
  /call FinishCasting
/return

Sub Buff
  /if (!${Me.Buff[Aura of Loyalty].ID}) /cast 11
/return

Sub Shining(Line, TARGET)
  /target ${TARGET}
  /delay 1
  /cast 4
  /call FinishCasting
/return

Sub GalvosRetort
  |/target Phrogeater
  /target ${Spawn[${watch}]}
  /delay 1
  /if (!${Target.Buff[Galvos' Retort].ID}) {
    /cast 12
	/call FinishCasting
  } else {
  }
  /if (!${Target.Buff[Shining Armor].ID}) {
    /cast 4
	/call FinishCasting
  } else {
  }
/return


Sub Attack
  /face fast
  /target ${Spawn[${combattarget}]}
  /delay 2
  |/if (!${Target.Dead} && ${Me.SpellReady[Mark of the Zealot]} && ${Target.ID} != ${Group.MainTank.ID} && !${Target.Buff[Mark of the Zealot].ID}) /casting "Mark of the Zealot" gem3
  |/call FinishCasting
  /if (${Target.Body.ID} == 3 && ${Me.SpellReady[Sermon of Rebuke]} && !${Target.Buff[Sermon of Rebuke].ID}) /cast 7
  /call FinishCasting
/return

Sub Med
  :Medititate
    /doevents
    /if ( !${Me.Sitting} ) /sit
  /if ( ${Me.PctMana} < 100 ) /goto :Medititate
/return

Sub FinishCasting
  :casting
    /doevents
  /if (${Me.Casting.ID}) /goto :casting
/return
