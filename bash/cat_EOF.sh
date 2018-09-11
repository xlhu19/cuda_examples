#!/bin/bash

# There should be no space before last EOF.
cat <<EOF
# Print line 1.
# Print line 2.
    # Print line 3.
EOF

# If use -, then it allows a tab before the 'end'.
cat <<-end
    # Print line 1.
    # Print line 2.
    # Print line 3.
	end

cat <<EOF > test.sh
#!/bin/bash
#you Shell script writes here.
EOF
