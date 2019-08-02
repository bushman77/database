Sub Combat
  /sqlite c:\macroquest2\partystate.db queue select * from combat;
  /varset combat ${sqlite.result[queue 1 combat]}
  /if ( ${sqlite.clear[queue]} ) {
  } else {
    /echo BOOOOOO
  }
/return

Sub CombatStartSQL
  /varset combat 1
  /sqlite c:\macroquest2\partystate.db queue update combat set combat = 1, combattarget = ${Target.ID};
  /if ( ${sqlite.clear[queue]} ) {
  } else {
    /echo BOOOOOO
  }
/return

Sub CombatOverSQL
  /varset combat 0
  /sqlite c:\macroquest2\partystate.db queue update combat set combat = 0, combattarget = 0;
  /if ( ${sqlite.clear[queue]} ) {
  } else {
    /echo BOOOOOO
  }
/return

#event State "<#*#> state"
Sub Event_State
  /bc _____________________________________ 
  /bc  Class: ${Me.Class.ID} Level: ${Me.Level} Exp: ${Me.Exp}
  /if (${combat} ==1) /bc CombatTarget: ${combattarget}
  /bc  Hp: ${Me.PctHPs} Mana: ${Me.PctMana}
/return

#event Invite                   "Phrogeater invites you to join a group."
Sub Event_Invite
  /keypress ctrl+i
/return


#event Exp                      "<#*#> exp"
Sub Event_Exp
  /bc ${Me.Exp}
/return

#event StartLocation "Your Location is #1#, #2#, #3#, and are heading #4#."
Sub Event_StartLocation
  /varset startx ${Param1}
  /varset starty ${Param2}
/return


Sub Initialze
  /declare combat int outer 0
  /declare combattarget int outer 0
  /declare swarm int outer 0
  /declare petattack int outer 0
  /declare servantcounter int outer 0
  
  |/declare nuke string outer "Beam of Razors"
  /declare nuke string outer "Blast of Sand"
  /declare counter int outer 0
/return

Sub FinishCasting
  :casting
    /doevents
  /if (${Me.Casting.ID}) /goto :casting
/return

Sub ServantCounter
  /varset servantcounter ${Math.Calc[${servantcounter}+1]}
/return
