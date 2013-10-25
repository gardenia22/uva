

SpeedFile = "input.in"#store speed with a src and des
PathFile = "input2.in"#store each path
SigmaThreshold = 0.5#Threshold Sigma value for second method


LinkMaxSpeed = Hash.new()#The max speed of a link
LinkAllSpeed = Hash.new()#All speeds showed up in a link
PathSpeed = Hash.new()#The speed of a path
LinkUps = Hash.new()#The upstream links of a link
LinkDowns = Hash.new()#The downstream links of a link

#read from SpeedFile
Input = IO.readlines(SpeedFile)

Input.each{
	|s|
	
	temp = s.split(' ')
	PathSpeed[temp[2]+"->"+temp[3]] = temp[4].split(',')
}

#read from PathFile
Input1 = IO.readlines(PathFile)
Input1.each{
	|s|
	temp = s.split(' ')
	Speednow = PathSpeed[temp.first+'->'+temp.last]
	temp.each_with_index{
		|x,i|
		if temp[i+1]!=nil
			linknow = x+'->'+temp[i+1]
			if (temp[i+1]!=nil) 
				if LinkAllSpeed[linknow]==nil
					LinkAllSpeed[linknow] = Array.new()
				end
				LinkAllSpeed[linknow].push(Speednow.first.to_i)
				if LinkMaxSpeed[linknow]==nil 
					LinkMaxSpeed[linknow] = 0
				end 
				if Speednow.first.to_i>LinkMaxSpeed[linknow]
					LinkMaxSpeed[linknow] = Speednow.first.to_i
				end
			end
			if LinkUps[linknow]==nil 
				LinkUps[linknow] = Array.new()
			end
			if (temp[i+2]!=nil)
				LinkUps[linknow].push(temp[i+1]+'->'+temp[i+2])
			end
			if LinkDowns[linknow]==nil 
				LinkDowns[linknow] = Array.new()
			end
			if (i-1>=0)
				LinkDowns[linknow].push(temp[i-1]+'->'+x)
			end
		end
	}
}
#end of input

#first method
puts "results of first method:"
LinkMaxSpeed.each {
	|linknow,speednow|
	flag = true
	count = 0
=begin
	puts "now the link is"
	puts linknow
	puts "uplinks are"
	puts LinkUps[linknow]
	puts "downlinks are"
	puts LinkDowns[linknow]
	puts "Max Speed is "
	puts LinkMaxSpeed[linknow]
=end
	LinkUps[linknow].uniq!#remove the duplicate element
	LinkDowns[linknow].uniq!

	LinkUps[linknow].each{
		|uplink|
		if LinkMaxSpeed[uplink]<LinkMaxSpeed[linknow]
			flag = false
		end
		if LinkMaxSpeed[uplink]==LinkMaxSpeed[linknow]
			count += 1
		end
	}
	LinkDowns[linknow].each{
		|downlink|
		if LinkMaxSpeed[downlink]<LinkMaxSpeed[linknow]
			flag = false
		end
		if LinkMaxSpeed[downlink]==LinkMaxSpeed[linknow]
			count +=1
		end
	}
	if count<LinkUps[linknow].size+LinkDowns[linknow].size && flag 
		puts linknow
	end
}

#second method

def sigma(allspeednow)#calculate sigma
	sum = 0.0
	allspeednow.each{
		|x|
		sum += x
	}
	avg = (sum/allspeednow.size)
	sig = 0.0
	allspeednow.each{
		|x|
		sig += (x-avg)*(x-avg)
	}
	return (sig/allspeednow.size).to_f
end

puts "--------------------------"
puts "results of second method:"
puts "Link Sigma"
LinkAllSpeed.each {
	|linknow,allspeednow|
	flag = true
	#if sigma(allspeednow)<SigmaThreshold
	puts "#{linknow}"+" #{sigma(allspeednow)}"
	#puts allspeednow
	#end
}

#third method
puts "--------------------------"
puts "results of third method:"
Input1.each{
	|s|
	temp = s.split(' ')
	Speednow = PathSpeed[temp.first+'->'+temp.last]
	puts "Probability for each link on Path #{temp.first+'->'+temp.last}:"
	puts "Link Probability"
	temp.each_with_index{
		|x,i|
		if temp[i+1]!=nil
			linknow = x+'->'+temp[i+1]
			count = 0.0
			LinkAllSpeed[linknow].each{
				|speed|
				if speed>Speednow.first.to_i
					count += 1;
				end
			}
			puts "#{linknow}"+" #{1-count/LinkAllSpeed.size}"
		end
	}
}	
