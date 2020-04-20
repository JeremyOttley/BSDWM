export LANG="en_AU.UTF-8"
export LC_ALL="en_AU.UTF-8"
xset +fp /home/cjg/.fonts
xset fp rehash
xrdb -merge .Xresources
exec ~/dots/nfs.sh &
compton -cCGb &
wal --vte -R
#feh --bg-scale /home/cjg/Wallpaper/darkgreen.jpg &
exec ~/dots/dwm-status.sh &
exec xautolock -time 20 -locker slock &

while :; do
	ssh-agent dwm
done

