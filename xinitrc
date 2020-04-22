export LANG="en_US.UTF-8"
export LC_ALL="en_US.UTF-8"
xset +fp /home/jottley/.fonts
xset fp rehash
xrdb -merge .Xresources
exec ~/.dwm/nfs.sh &
compton -cCGb &
wal --vte -R
#feh --bg-scale /home/jottley/.wallpapers/jfirew.png &
exec ~/.dwm/dwm-status.sh &
exec xautolock -time 20 -locker slock &

while :; do
	ssh-agent dwm
done

